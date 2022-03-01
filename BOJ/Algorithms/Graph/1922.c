#include <stdio.h>
#include <stdlib.h>
#define MAX 100001
#define TRUE 1
#define FALSE 0
int N, M;
int Parent[MAX];

typedef struct Element{
    int cost;
    int src;
    int dst;
} Element;

int cmp(const void *a, const void *b){
    return ((Element*)a)->cost - ((Element*)b)->cost;
}

int getParent(int num){
    if(num == Parent[num]) return num;
    return Parent[num] = getParent(Parent[num]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) Parent[a] = b;
}

int findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return TRUE;
    else return FALSE;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int result = 0;
    Element Arr[M];
    for(int i = 0; i < M; i++){
        int src, dst, cost;
        scanf("%d %d %d", &src, &dst, &cost);
        Arr[i].cost = cost;
        Arr[i].src = src;
        Arr[i].dst = dst;
    }
    for(int i = 1; i <= N; i++) Parent[i] = i;
    qsort(Arr, M, sizeof(Arr[0]), cmp);
        for(int i = 0; i < M; i++){
        int cost = Arr[i].cost;
        int src = Arr[i].src;
        int dst = Arr[i].dst;
        if(!findParent(src, dst)){
            result += cost;
            unionParent(src, dst);
        }
    }
    printf("%d\n", result);
}
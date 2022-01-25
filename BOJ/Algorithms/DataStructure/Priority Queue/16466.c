#include <stdio.h>
#include <stdlib.h>
#define MAX 51
int Arr[MAX];

int compare (void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &Arr[i]);
    }
    qsort(Arr, N, sizeof(int), compare);
    int answer = 0;

    for(int i = 1; i <= N; i++){
        if(Arr[i] - answer == 1){
            answer = Arr[i];
        }
        else{
            answer++;
            break;
        }
    }
    printf("%d\n", answer);
}
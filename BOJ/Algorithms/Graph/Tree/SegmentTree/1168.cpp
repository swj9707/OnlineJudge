#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int arr[MAX];
int tree[MAX * 4];

int init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int update(int start, int end, int node, int diff){
    tree[node]--;
    if(start == end) return 0;
    else {
        int mid = (start + end) / 2;
        if(diff <= mid) return update(start, mid, node * 2, diff);
        else return update(mid + 1, end, node * 2 + 1, diff);
    }
}

int query(int start, int end, int node, int order){
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(order <= tree[2 * node]) return query(start, mid, 2 * node, order);
    else return query(mid + 1, end, node * 2 + 1, order);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int index = 1;
    for(int i = 0; i < N; i++) arr[i] = i + 1;
    init(0, N-1, 1);
    cout << "<";
    for(int i = 0; i < N; i++){
        int size = N - i;
        index += M - 1;
        if(index % size == 0) index = size;
        else if (index > size) index %= size;

        int num = query(0, N-1, 1, ind)
    }
}

#include <iostream>
#define MAX 1000001
using namespace std;

int tree[MAX * 4];

int maxValue(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return max(maxValue(start, mid, node * 2, left, right), maxValue(mid + 1, end, node * 2 + 1, left, right));
}

void update(int start, int end, int node, int index, int value){
    if(index < start || index > end) return;
    if(start == end) {
        tree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, value);
    update(mid + 1, end, node * 2 + 1, index, value);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        update(0, N-1, 1, i, x);
    }
    for(int i = M - 1; i < N - M + 1; i++) cout << maxValue(0, N-1, 1, i - (M-1), i + (M-1)) << " ";
}
#include <iostream>
#include <vector>
#define MAX 1000002
#define ll long long
using namespace std;

ll arr[MAX];
ll tree[MAX * 4];

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);   
}

void update(int start, int end, int node, int index, ll diff){
    if(index < start || index > end) return;
    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, diff);
    update(mid + 1, end, node * 2 + 1, index, diff);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    init(0, N-1, 1);
    
    for(int i = 0; i < M; i++){
        int query, a, b;
        cin >> query >> a >> b;
        if(query == 0) {
            if(a > b) swap(a, b);
            cout << sum(0, N-1, 1, a-1, b-1) << '\n';
        } else {
            ll diff = b - arr[a-1];
            arr[a-1] = b;
            update(0, N-1, 1, a-1, diff);
        }
    }
}
#include <iostream>
#define MAX 100001
#define ll long long
using namespace std;

ll arr[MAX];
ll tree[MAX * 4];

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid+1, end, node * 2 + 1);
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
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> arr[i];
    init(0, N-1, 1);
    for(int i = 0; i < Q; i++){
        int x, y, a;
        ll b;
        cin >> x >> y >> a >> b;
        x--; y--; a--;
        int left = min(x, y);
        int right = max(x, y);
        cout << sum(0, N-1, 1, left, right) << '\n';
        ll diff = b - arr[a];
        arr[a] = b;
        update(0, N-1, 1, a, diff);
    }

}
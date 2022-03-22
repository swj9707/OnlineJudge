#include <iostream>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
using namespace std;

ll arr[MAX];
ll tree[4 * MAX];

ll init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) % MOD) * (init(mid + 1, end, node * 2 + 1) % MOD); 
}

ll mult(int start, int end, int left, int right, int node){
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/ 2;
    return (mult(start, mid, left, right, node * 2) % MOD) * (mult(mid + 1, end, left, right, node * 2 + 1) % MOD);
}

ll update(int start, int end, int node, int index, ll diff){
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = diff;
    int mid = (start + end) / 2;
    return tree[node] = (update(start, mid, node * 2, index, diff) % MOD) * (update(mid+1, end, node * 2 + 1, index, diff) % MOD);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];
    init(0, N-1, 1);
    int a, b; ll c;
    for(int i = 0; i < M + K; i++){
        cin >> a >> b >> c;
        if(a == 1){
            int index = b - 1;
            update(0, N - 1, 1, index, c);
        }
        else if (a == 2){
            cout << mult(0, N - 1, b-1, c-1, 1) % MOD << '\n';
        }
    }
}
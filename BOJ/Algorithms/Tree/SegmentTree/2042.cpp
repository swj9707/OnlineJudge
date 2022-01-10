#include <iostream>
#define ll long long
#define MAX 1000000
using namespace std;

ll arr[MAX];
ll tree[4*MAX];


void init_set(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

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
    init_set();
    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];
    init(0, N-1, 1);
    int a,b;
    ll c;
    for(int i = 0; i < M + K; i++){
        cin >> a >> b >> c;
        if(a == 1){
            int index = b - 1;
            ll diff = c - arr[index];
            arr[index] = c;
            update(0, N - 1, 1, index, diff);
        }
        else{
            cout << sum(0, N - 1, 1, b-1, c-1) << '\n';
        }
    }
}
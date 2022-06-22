#include <iostream>
#define MAX 500001
#define ll long long
using namespace std;

int arr[MAX];
int second[MAX * 2];
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

void update(int start, int end, int node, int index){
    if(index < start || index > end) return;
    tree[node] += 1;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index);
    update(mid + 1, end, node * 2 + 1, index);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    ll answer = 0;
    for(int i = 1; i <= N; i++){
        cin>> arr[i];
    }
    for(int i = 1; i <= N; i++){
        int x; cin >> x;
        second[x] = i;
    }
    for(int i = 1; i <= N; i++){
        int src = second[arr[i]];
        ll tmp = sum(1, N, 1, src+1, N);
        update(1, N, 1, src);
        answer += tmp;
    }
    cout << answer << '\n';
}
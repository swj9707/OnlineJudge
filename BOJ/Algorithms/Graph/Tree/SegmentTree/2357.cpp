#include <iostream>
#define MAX 100001
#define MAXVALUE 1000000001
#define ll long long
using namespace std;

ll arr[MAX];
ll maxTree[MAX * 4];
ll minTree[MAX * 4];

ll maxinit(int start, int end, int node){
    if(start == end) return maxTree[node] = arr[start];
    int mid = (start + end) / 2;
    return maxTree[node] = max(maxinit(start, mid, node * 2), maxinit(mid + 1, end, node * 2 + 1));
}

ll mininit(int start, int end, int node){
    if(start == end) return minTree[node] = arr[start];
    int mid = (start + end) / 2;
    return minTree[node] = min(mininit(start, mid, node * 2), mininit(mid + 1, end, node * 2 + 1));
}

ll findValue(int start, int end, int left, int right, int node, bool maximum){
    if(left > end || right < start){
        if(maximum) return MAXVALUE;
        else return -MAXVALUE;
    }
    if(left <= start && end <= right){
        if(maximum) return maxTree[node];
        else return minTree[node];
    }
    int mid = start + (end - start) / 2;
    if(maximum) return max(findValue(start, mid, left, right, node * 2, maximum),findValue(mid+1, end, left, right, node * 2 + 1, maximum));
    else return min(findValue(start, mid, left, right, node * 2, maximum),findValue(mid+1, end, left, right, node * 2 + 1, maximum));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 0; i < MAX * 4 ; i++) minTree[i] = MAXVALUE;
    maxinit(0, N-1, 1);
    mininit(0, N-1, 1);
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        int left, right;
        right = a > b ? a : b;
        left = a > b ? b : a;
        cout << findValue(0, N-1, left - 1, right - 1, 1, false) << " " << findValue(0, N-1, left-1, right-1, 1, true) << '\n';
    }
}
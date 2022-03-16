#include <iostream>
#define MAXVALUE 1000000001
#define MAX 100001
using namespace std;

int arr[MAX];
int minTree[4 * MAX];

int init(int start, int end, int node){
    if(start == end) return minTree[node] = arr[start];
    int mid = (start + end) / 2;
    return minTree[node] = min(init(start, mid, 2 * node), init(mid+1, end, 2 * node + 1)); 
}

int findValue(int start, int end, int left, int right, int node){
    if (left > end || right < start) return MAXVALUE;
    if (left <= start && end <= right) return minTree[node];
    int mid = (start + end)/2;
    return min(findValue(start, mid, left, right, node * 2), findValue(mid + 1, end, left, right, node * 2 + 1));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 0; i < 4 * N; i++) minTree[i] = MAXVALUE;
    for(int i = 0; i < N; i++) cin >> arr[i];
    init(0, N-1, 1);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        int left = min(a, b);
        int right = max(a, b);
        cout << findValue(0, N-1, left - 1, right - 1, 1) << '\n';
    }
}
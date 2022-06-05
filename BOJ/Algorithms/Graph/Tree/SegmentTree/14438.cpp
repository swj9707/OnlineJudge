#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
#define MAX 100001
using namespace std;

int arr[MAX];
vector<int> tree(MAX * 4);

int init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(start, mid, node * 2), init(mid+1, end, node*2 + 1));
}

int update(int start, int end, int node, int index, int data){
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = data;
    int mid = (start + end) / 2;
    return tree[node] = min(update(start, mid, node * 2, index, data), update(mid + 1, end, node * 2 + 1, index, data));
}

int query(int start, int end, int node, int left, int right){
    if(left > end || start > right) return INF;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return min(query(start, mid, node * 2, left, right), query(mid+1, end, node * 2 + 1, left, right));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    int M; cin >> M;
    init(0, N-1, 1);
    for(int i = 0; i < M; i++){
        int oper, x, y;
        cin >> oper >> x >> y;
        if(oper == 1){
            update(0, N-1, 1, x-1, y);
        } else {
            cout << query(0, N-1, 1, x-1, y-1) << "\n";
        }
    }
}
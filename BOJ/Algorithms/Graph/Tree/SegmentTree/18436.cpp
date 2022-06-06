#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int arr[MAX];
vector<int> tree(MAX*4);

int init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, int val){
    if(index < start || end < index) return;
    tree[node] += val;
    if(start != end){
        int mid = (start + end) / 2;
        update(start, mid, node * 2, index, val);
        update(mid + 1, end, node * 2 + 1, index, val);
    }
}

int query(int start, int end, int left, int right, int node){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) + query(mid+1, end, left, right, node * 2 + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x % 2 == 1) arr[i] = 1;
    }
    int Q; cin >> Q;
    init(0, N-1, 1);
    for(int i = 0; i < Q; i++){
        int oper, x, y;
        cin >> oper >> x >> y;
        if(oper == 1){
            y = y % 2;
            if(arr[x-1] != y){
                if(y == 1) update(0, N-1, 1, x-1, 1);
                else update(0, N-1, 1, x-1, -1);
                arr[x-1] = y;
            }
        }else if (oper == 2){
            cout << y - x + 1 - query(0, N-1, x-1, y-1, 1) << "\n";
        }else{
            cout << query(0, N-1, x-1, y-1, 1) << "\n";
        }
    }
}
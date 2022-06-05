#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int arr[MAX];
int tree[4 * MAX];

int init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2)) * (init(mid + 1, end, node * 2 + 1)); 
}

int mult(int start, int end, int left, int right, int node){
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/ 2;
    return (mult(start, mid, left, right, node * 2)) * (mult(mid + 1, end, left, right, node * 2 + 1));
}

int update(int start, int end, int node, int index, int diff){
    if(index < start || index > end) return tree[node];
    if(start == end) return tree[node] = diff;
    int mid = (start + end) / 2;
    return tree[node] = (update(start, mid, node * 2, index, diff)) * (update(mid+1, end, node * 2 + 1, index, diff) );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    while(cin >> N >> K){
        for(int i = 0; i < N; i++){
            int x; cin >> x;
            if(x > 0) arr[i] = 1;
            else if(x == 0) arr[i] = 0;
            else arr[i] = -1;
        }
        init(0, N-1, 1);
        for(int i = 0; i < K; i++){
            char C; cin >> C;
            int a, b; cin >> a >> b;
            if(C == 'C'){
                int data;
                if(b > 0) data = 1;
                else if (b == 0) data = 0;
                else data = -1;
                update(0, N-1, 1, a-1, data);
            }else{
                long long result = mult(0, N-1, a-1, b-1, 1);
                if(result > 0) cout << "+";
                else if (result == 0) cout <<"0";
                else cout << "-";
            }
        }
        cout << '\n';
    }
}
#include <iostream>
#define MAX 65536
#define ll long long
using namespace std;
int arr[250001];
int tree[MAX * 4];

int update(int start, int end, int node, int index, int value){
    if(index < start || end < index) return tree[node];
    if(start == end){
        tree[node] += value;
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, index, value) + update(mid + 1, end, node * 2 + 1, index, value);
}

int midValue(int node, int left, int right, int value){
    if(left == right) return left;
    int mid = (left + right) / 2;
    if(tree[node * 2] >= value) return midValue(node * 2, left, mid, value);
    else return midValue(node * 2 + 1, mid + 1, right, value - tree[node * 2]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < K; i++){
        update(0, MAX, 1, arr[i], 1);
    }
    ll answer;
    answer = midValue(1, 0, MAX, (K+1)/2);
    for(int i = K; i < N; i++){
        update(0, MAX, 1, arr[i], 1);
        update(0, MAX, 1, arr[i-K], -1);
        int mid = midValue(1, 0, MAX, (K+1)/2);
        answer += mid;
    }
    cout << answer << '\n';
}
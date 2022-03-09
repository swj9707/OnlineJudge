#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int Parent[MAX];

int getParent(int X){
    if(X == Parent[X]) return X;
    return Parent[X] = getParent(Parent[X]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) Parent[a] = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    long long answer = 0, sum = 0;
    int count = 0;
    for(int i = 0; i <= N; i++) Parent[i] = i;
    vector<pair<long long, pair<int, int>>> edge(M);
    for(int i = 0; i < M; i++){
        int u, v;
        long long cost;
        cin >> u >> v >> cost;
        edge[i] = {cost, {u, v}};
        sum += cost;
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < M; i++){
        long long cost = edge[i].first;
        int src = edge[i].second.first;
        int dst = edge[i].second.second;
        if(!findParent(src, dst)){
            unionParent(src, dst);
            answer += cost;
            count++;
        }
    }
    if(count == N - 1) cout << sum - answer << '\n';
    else cout << "-1\n";
}
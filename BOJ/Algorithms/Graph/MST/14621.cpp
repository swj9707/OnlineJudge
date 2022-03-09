#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
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
    int answer = 0, count = 0;
    vector<pair<int, pair<int, int>>> edge;
    vector<char> sexData(N+1);
    for(int i = 0; i <= N; i++) Parent[i] = i;
    for(int i = 1 ; i <= N; i++) cin >> sexData[i];
    for(int i = 0; i < M; i++){
        int u, v, d; cin >> u >> v >> d;
        if(sexData[u] != sexData[v]){
            edge.push_back({d, {u, v}});
        }
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        int cost = edge[i].first;
        int src = edge[i].second.first;
        int dst = edge[i].second.second;
        if(!findParent(src, dst)){
            unionParent(src, dst);
            answer += cost;
            count++;
        }
    }
    if(count == N - 1) cout << answer << '\n';
    else cout << "-1\n";
}
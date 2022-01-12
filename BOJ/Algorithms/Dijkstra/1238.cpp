#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 99999999
using namespace std;

int N, M, X;
int Dist[MAX];
int Result[MAX];
vector<pair<int, int>> edge[MAX];

void Dijkstra(int start){
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, start});
    Dist[start] = 0;
    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int Cur  = PQ.top().second;
        PQ.pop();
        if(Dist[Cur] < Cost) continue;
        for(int i = 0; i < edge[Cur].size(); i++){
            int Next = edge[Cur][i].first;
            int nCost = edge[Cur][i].second;
            if(Dist[Next] > Cost + nCost){
                Dist[Next] = Cost + nCost;
                PQ.push({-Dist[Next], Next});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) Dist[j] = INF;
        Dijkstra(i);
        Result[i] = Dist[X];
    }
    for(int i = 1; i <= N; i++) Dist[i] = INF;
    Dijkstra(X);
    for(int i = 1; i <= N; i++) Result[i] += Dist[i];
    sort(Result + 1, Result + N + 1);
    cout << Result[N] << '\n';
}
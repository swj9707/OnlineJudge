#include <iostream>
#include <queue>
#include <vector>
#define INF 9999999
#define MAX 200001

using namespace std;

int Dist[MAX];
vector<pair<int, int>> edge[MAX];

void Dijkstra(int Start){
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, Start});
    Dist[Start] = 0;
    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
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
    int V, E, Start;
    cin >> V >> E >> Start;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }
    for(int i = 1; i <= V; i++) Dist[i] = INF;
    Dijkstra(Start); 
    for (int i = 1; i <= V; i++){
        if (Dist[i] == INF) cout << "INF" << '\n';
        else cout << Dist[i] << '\n';
    }
}
#include <iostream>
#include <vector>
#include <queue>
#define MAX 50001
#define INF 9999
using namespace std;

vector<pair<int, int>> edge[MAX];
int Dist[MAX];

void Dijkstra(){
    fill_n(Dist, MAX, INF);
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, 1});
    while(!PQ.empty()){
        int cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        if(Dist[Cur] < cost) continue;
        for(int i = 0; i < edge[Cur].size(); i++){
            int next = edge[Cur][i].first;
            int nCost = edge[Cur][i].second + cost;
            if(Dist[next] > nCost){
                Dist[next] = nCost;
                PQ.push({-nCost, next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++){
        int src, dst, cost; cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
    Dijkstra();
    cout << Dist[N] << '\n';
}
#include <iostream>
#include <queue>
#include <vector>
#define MAX 801
#define INF 987654321
using namespace std;

int N, E;

int Dist[MAX];
vector<pair<int, int>> edge[MAX];

void Dijkstra(int Start){
    for(int i = 1; i <= N; i++) Dist[i] = INF;
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, Start});
    Dist[Start] = 0;
    while(!PQ.empty()){
        int Cost = PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        if(Dist[Cur] < Cost) continue;
        for(int i = 0; i < edge[Cur].size(); i++){
            int Next = edge[Cur][i].first;
            int nCost = edge[Cur][i].second;
            if(Dist[Next] > Cost + nCost){
                Dist[Next] = Cost + nCost;
                PQ.push({Dist[Next], Next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer;
    cin >> N >> E;
    for(int i = 1; i <= E; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
    int v1, v2;
    cin >> v1 >> v2;
    Dijkstra(1);
    int to_V1 = Dist[v1];
    int to_V2 = Dist[v2];
    Dijkstra(v1);
    int v1_to_v2 = Dist[v2];
    int v1_to_N = Dist[N];
    Dijkstra(v2);
    int v2_to_N = Dist[N];
    
    answer = min(to_V1 + v1_to_v2 + v2_to_N, to_V2 + v1_to_v2 + v1_to_N);
    if(v1_to_v2 == INF || answer == INF) cout << "-1\n";
    else cout << answer << '\n';
    return 0;
}
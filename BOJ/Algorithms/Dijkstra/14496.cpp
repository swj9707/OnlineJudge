#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 987654321
using namespace std;

int a, b;
int N, M;
int Dist[MAX];
vector<pair<int, int>> edge[MAX];

void Dijkstra(int start){
    for(int i = 1; i <= N; i++) Dist[i] = INF;
    priority_queue<pair<int, int>> PQ;
    Dist[start] = 0;
    PQ.push({0, start});
    while(!PQ.empty()){
        int Cur = PQ.top().second;
        int Cost = PQ.top().first;
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
    cin >> a >> b;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int src, dst;
        cin >> src >> dst;
        edge[src].push_back({dst, 1});
        edge[dst].push_back({src, 1});
    }
    Dijkstra(a);
    cout << Dist[b] << '\n';   
}
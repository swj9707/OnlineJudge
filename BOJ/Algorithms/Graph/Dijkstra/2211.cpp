#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 9876543
using namespace std;

vector<pair<int, int>> edge[MAX];
int Dist[MAX];
int Parent[MAX];

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
                Parent[Next] = Cur;
                PQ.push({-Dist[Next], Next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
    for(int i = 0; i < MAX; i++) Dist[i] = INF;
    Dijkstra(1);
    cout << N - 1 << '\n';
    for(int i = 2; i <= N; i++){
        cout << Parent[i] << " " << i << '\n';
    }
}
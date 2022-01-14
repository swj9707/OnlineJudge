#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 987654321
using namespace std;


int N, M;
int Start, End;
int Dist[MAX];
vector<pair<int, int>> edge[MAX];

void Dijkstra(){
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
    cout << Dist[End] << '\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
    }
    cin >> Start >> End;
    for(int i = 1; i <= N; i++) Dist[i] = INF;
    Dijkstra();
}
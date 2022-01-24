#include <iostream>
#include <queue>
#include <vector>
#define MAX 300001
#define INF 987654321
using namespace std;

int N, M, K, Start;
int Dist[MAX];
vector<pair<int, int>> edge[MAX];

void Dijkstra(int Start){
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, Start});
    Dist[Start] = 0;
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
    cin >> N >> M >> K >> Start;
    for(int i = 1; i <= N; i++) Dist[i] = INF;
    for(int i = 0; i < M; i++){
        int src, dst;
        cin >> src >> dst;
        edge[src].push_back({dst, 1});
    }
    Dijkstra(Start);
    bool flag = false;
    for(int i = 1; i <= N; i++){
        if(Dist[i] == K) {
            cout << i << '\n';
            flag = true;
        }
    }
    if(!flag) cout << "-1\n";
}
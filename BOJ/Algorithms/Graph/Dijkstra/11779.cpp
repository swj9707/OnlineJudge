#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 987654321
using namespace std;

int N, M;
vector<pair<int, int>> edge[MAX];
int Dist[MAX];
int Route[MAX];

void Dijkstra(int Start){
    for(int i = 1; i <= N; i++) Dist[i] = INF;
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, Start});
    Dist[Start] = 0;
    while(!PQ.empty()){
        int Curr = PQ.top().second;
        int Cost = PQ.top().first;
        PQ.pop();
        if(Dist[Curr] < Cost) continue;
        for(int i = 0; i < edge[Curr].size(); i++){
            int Next = edge[Curr][i].first;
            int nCost = edge[Curr][i].second;
            if(Dist[Next] > Cost + nCost){
                Route[Next] = Curr;
                Dist[Next] = Cost + nCost;
                PQ.push({Dist[Next], Next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int src, dst, cost;
    for(int i = 0; i < M; i++){
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
    }
    cin >> src >> dst;
    Dijkstra(src);
    vector<int> routeVector;
    cout << Dist[dst] << '\n';
    while(dst){
        routeVector.push_back(dst);
        dst = Route[dst];
    }
    cout << routeVector.size() << '\n';
    for(int i = routeVector.size()-1; i >= 0; i--) cout << routeVector[i] << " ";
}
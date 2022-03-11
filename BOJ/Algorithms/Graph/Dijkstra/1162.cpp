#include <iostream>
#include <queue>
#include <vector>
#define INF 9876543
#define MAX 10001
#define ll long long
using namespace std;

vector<pair<int, int>> edge[MAX];
ll Dist[MAX][21];

void Dijkstra(int K){
    priority_queue<pair<ll, pair<int, int>>> PQ;
    PQ.push({0, {1, 0}});
    Dist[1][0] = 0;
    while(!PQ.empty()){
        int Current = PQ.top().second.first;
        int count = PQ.top().second.second;
        ll cost = -PQ.top().first;
        PQ.pop();
        if(Dist[Current][count] < cost) continue;
        for(int i = 0; i < edge[Current].size(); i++){
            int next = edge[Current][i].first;
            ll nCost = edge[Current][i].second + cost;
            if(Dist[next][count] > nCost){
                Dist[next][count] = nCost;
                PQ.push({-nCost, {next, count}});
            }
            if(Dist[next][count+1] > cost && count+1 <= K){
                Dist[next][count+1] = cost;
                PQ.push({-cost, {next, count+1}});
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll answer = INF;
    int N, M, K; cin >> N >> M >> K;
    for(int i = 0 ; i < M; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
    for(int i = 0; i < MAX; i++) fill_n(Dist[i], 21, INF);
    Dijkstra(K);
    for(int i = 0; i <= K; i++) answer = min(answer, Dist[N][i]);
    cout << answer << '\n';
}
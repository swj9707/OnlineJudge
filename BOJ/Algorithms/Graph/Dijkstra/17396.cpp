#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
#define INF 10000000001
#define ll long long
using namespace std;

vector<pair<int, long long>> edge[MAX];
ll Dist[MAX];
int Vision[MAX];

void Dijkstra(){
    fill_n(Dist, MAX, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> PQ;
    Dist[0] = 0;
    PQ.push({0, 0});
    while(!PQ.empty()){
        int cur = PQ.top().second;
        ll cost = PQ.top().first;
        PQ.pop();
        if(Dist[cur] < cost) continue;
        for(int i = 0; i < edge[cur].size(); i++){
            int next = edge[cur][i].first;
            ll nCost = edge[cur][i].second;
            if(Dist[next] > nCost + cost){
                Dist[next] = nCost + cost;
                PQ.push({Dist[next], next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> Vision[i];
    Vision[N-1] = 0;
    for(int i = 0; i < M; i++){
        int src, dst, cost; cin >> src >> dst >> cost;
        if(Vision[src] == 0 && Vision[dst] == 0){
            edge[src].push_back({dst, cost});
            edge[dst].push_back({src, cost});
        }
    }
    Dijkstra();
    if(Dist[N-1] == INF) cout << "-1\n";
    else cout << Dist[N-1] << '\n';
}
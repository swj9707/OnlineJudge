#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 2010
#define INF 987654
using namespace std;

vector<pair<int, int>> edge[MAX];
set<int> candidate;
int Dist_S[MAX];
int Dist_G[MAX];
int Dist_H[MAX];
void init(){
    for(int i = 0; i < MAX; i++) edge[i].clear();
    for(int i = 0; i < MAX; i++) Dist_S[i] = INF;
    for(int i = 0; i < MAX; i++) Dist_G[i] = INF;
    for(int i = 0; i < MAX; i++) Dist_H[i] = INF;
    candidate.clear();
}

void Dijkstra(int start, int *Dist){
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, start});
    while(!PQ.empty()){
        int cost = -PQ.top().first;
        int current = PQ.top().second;
        PQ.pop();
        if(Dist[current] < cost) continue;
        for(int i = 0; i < edge[current].size(); i++){
            int next = edge[current][i].first;
            int nCost = edge[current][i].second + cost;
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
    int T; cin >> T;
    while(T--){
        init();
        int n, m, t; cin >> n >> m >> t;
        int s, g, h; cin >> s >> g >> h;
        for(int i = 0; i < m; i++){
            int a, b, d; cin >> a >> b >> d;
            edge[a].push_back({b, d});
            edge[b].push_back({a, d});
        }
        for(int i = 0; i < t; i++){
            int a; cin >> a;
            candidate.insert(a);
        }
        Dijkstra(s, Dist_S);
        Dijkstra(g, Dist_G);
        Dijkstra(h, Dist_H);
        int Dist_GH = Dist_G[h];
        for(auto i : candidate){
            if(Dist_S[i] == Dist_S[g] + Dist_G[h] + Dist_H[i]) cout << i << " ";
            else if (Dist_S[i] == Dist_S[h] + Dist_G[h] + Dist_G[i]) cout << i << " ";
        }
        cout << '\n';
    }
}
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

vector<pair<int, int>> edge[MAX];
int Dist[MAX];
int BFS(int src, int dst){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < edge[x].size(); i++){
            int nx = edge[x][i].first;
            int cost = edge[x][i].second;
            if(Dist[nx] > 0) continue;
            Dist[nx] = Dist[x] + cost;
            q.push(nx);
        }
    }
    return Dist[dst];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N - 1; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
    for(int i = 0; i < M; i++){
        int src, dst;
        fill_n(Dist, MAX, 0);
        cin >> src >> dst;
        cout << BFS(src, dst) << '\n';
    }
}
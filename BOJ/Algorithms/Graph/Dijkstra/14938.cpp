#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 98765
using namespace std;

vector<pair<int, int>> edge[MAX];
vector<int> items(MAX);
int Dist[MAX];

int Dijkstra(int start, int N, int M){
    int answer = 0;
    fill_n(Dist, MAX, INF);
    priority_queue<pair<int, int>> PQ;
    Dist[start] = 0;
    PQ.push({0, start});
    while(!PQ.empty()){
        int Cur = PQ.top().second;
        int Cost = -PQ.top().first;
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
    for(int i = 1; i <= N; i++){
        if(Dist[i] <= M) answer += items[i];
    }
    return answer;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, R;
    int answer = 0;
    cin >> N >> M >> R;
    for(int i = 1; i <= N; i++) cin >> items[i];
    for(int i = 1; i <= R; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
    for(int i = 1; i <= N; i++){
        int result = Dijkstra(i, N, M);
        answer = max(answer, result);
    }
    cout << answer << '\n';
}
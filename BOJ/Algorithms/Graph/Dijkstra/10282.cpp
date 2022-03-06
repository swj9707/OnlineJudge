#include <iostream>
#include <queue>
#include <vector>
#define MAX 10001
#define INF 98765432
using namespace std;

int Dist[MAX];
vector<pair<int, int>> edge[MAX];

void Dijkstra(int N, int C){
    fill_n(Dist, MAX, INF);
    Dist[C] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, C});
    while(!PQ.empty()){
        int Current = PQ.top().second;
        int Cost = PQ.top().first;
        PQ.pop();
        if(Dist[Current] < Cost) continue;
        for(int i = 0; i < edge[Current].size(); i++){
            int Next = edge[Current][i].first;
            int nCost = edge[Current][i].second + Cost;
            if(Dist[Next] > nCost){
                Dist[Next] = nCost;
                PQ.push({nCost, Next});
            }
        }
    }
    int count = 0, answer = 0;
    for(int i = 1; i <= N; i++){
        if(Dist[i] != INF){
            count++;
            answer = max(answer, Dist[i]);
        }
    }
    cout << count << " " << answer << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TestCase; cin >> TestCase;
    while(TestCase--){
        for(int i = 0; i < MAX; i++) edge[i].clear();
        int N, D, C;
        cin >> N >> D >> C;
        for(int i = 0; i < D; i++){
            int src, dst, cost;
            cin >> src >> dst >> cost;
            edge[dst].push_back({src, cost});
        }
        Dijkstra(N, C);
    }
}
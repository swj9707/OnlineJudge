#include <iostream>
#include <queue>
#include <vector>
#define INF 9999999
#define MAX 1001
using namespace std;

priority_queue<int> Dist[MAX];
vector<pair<int, int>> edge[MAX];
int N, M, K;
    
void Dijkstra(int Start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> PQ;
    PQ.push({0, Start});
    Dist[1].push(0);
    while(!PQ.empty()){
        int Cost = PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        for(int i = 0; i < edge[Cur].size(); i++){
            int Next = edge[Cur][i].first;
            int nCost = edge[Cur][i].second;
            if(Dist[Next].size() < K){
                Dist[Next].push(Cost + nCost);
                PQ.push({Next, Cost + nCost});
            }
            else if(Dist[Next].top() > Cost + nCost){
                Dist[Next].pop();
                Dist[Next].push(Cost + nCost);
                PQ.push({Next,Cost + nCost});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int U, V, W;
        cin >> U >> V >> W;
        edge[U].push_back({V, W});
    }
    Dijkstra(1);
    for(int i = 1; i <= N; i++){
        if(Dist[i].size() < K) cout << "-1\n";
        else cout << Dist[i].top() << '\n';
    }
}
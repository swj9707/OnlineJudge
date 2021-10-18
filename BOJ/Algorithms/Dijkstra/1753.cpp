#include <iostream>
#include <queue>
#include <vector>
#define INF 9999999
#define MAX 200001

using namespace std;


int V, E, Start;
int Dist[MAX];
vector<pair<int, int>> VerTex[MAX];

void Dijkstra(){
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, Start});
    Dist[Start] = 0;
    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        for(int i = 0; i < VerTex[Cur].size(); i++){
            int Next = VerTex[Cur][i].first;
            int nCost = VerTex[Cur][i].second;
            if(Dist[Next] > Cost + nCost){
                Dist[Next] = Cost + nCost;
                PQ.push({-Dist[Next], Next});
            }
        }
    }
}

int main(){
    cin >> V >> E >> Start;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        VerTex[a].push_back({b, c});
    }
    for(int i = 1; i <= V; i++) Dist[i] = INF;
    Dijkstra(); 
    for (int i = 1; i <= V; i++){
        if (Dist[i] == INF) cout << "INF" << endl;
        else cout << Dist[i] << endl;
    }
}
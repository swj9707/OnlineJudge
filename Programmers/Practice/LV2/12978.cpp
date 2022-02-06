#include <iostream>
#include <vector>
#include <queue>
#define MAX 51
#define INF 98765432
using namespace std;

int Dist[MAX];
int edge[MAX][MAX];

void Dijkstra(int N){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    PQ.push({0, 1});
    Dist[1] = 0;
    while(!PQ.empty()){
        int Cur = PQ.top().second;
        int Cost = PQ.top().first;
        PQ.pop();
        if(Dist[Cur] < Cost) continue;
        for(int i = 1; i <= N; i++){
            if(edge[Cur][i] != 0){
                int next = i;
                int nCost = edge[Cur][next];
                if(Dist[next] > nCost + Cost){
                    Dist[next] = nCost + Cost;
                    PQ.push({nCost + Cost, next});
                }
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(auto i : road){
        int src = i[0], dst = i[1], cost = i[2];
        if(edge[src][dst] == 0){
            edge[src][dst] = cost;
            edge[dst][src] = cost;
        }
        else{
            edge[src][dst] = min(edge[src][dst], cost);
            edge[dst][src] = min(edge[dst][src], cost);
        }
    }
    
    for(int i = 1; i <= N; i++) Dist[i] = INF;
    Dijkstra(N);
    for(int i = 1; i <= N; i++){
       if(Dist[i] <= K) answer++;
    }

    return answer;
}
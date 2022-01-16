#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

int V, E;
vector<pair<int, int>> edge[MAX];
bool visited[MAX];

int prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int result = 0;
    for(int i = 1; i <= V; i++){
        while(!pq.empty() && visited[pq.top().second]){
            pq.pop();
        }
        int next = pq.top().second;
        int minCost = pq.top().first;

        visited[next] = true;
        result += minCost;
        for(auto i : edge[next]){
            pq.push({i.second, i.first});
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
    cout << prim() << '\n';
}
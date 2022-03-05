#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
using namespace std;

int Dist[MAX];
int N, D;
vector<pair<int, int>> edge[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> D;
    for(int i = 0; i < MAX; i++) Dist[i] = i;
    for(int i = 0; i < N; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        if(dst - src <= cost) continue;
        if(dst > D) continue;
        edge[src].push_back({dst, cost});
    }
    int before;
    Dist[0] = 0;
    for(int i = 0; i <= D; i++){
        if(i == 0) before = -1;
        else before = Dist[i-1];
        Dist[i] = min(Dist[i], before+1);
        if(!edge[i].empty()){
            for(int j = 0; j < edge[i].size(); j++){
                int cur = edge[i][j].first;
                int cost = edge[i][j].second;
                if(cur > D) continue;
                if(Dist[i] + cost < Dist[cur]){
                    Dist[cur] = Dist[i] + cost;
                }
            }
        }
    }
    cout << Dist[D];
}
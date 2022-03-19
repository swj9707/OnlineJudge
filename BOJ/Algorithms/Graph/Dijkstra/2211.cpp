#include <iostream>
#include <vector>
#define MAX 1001
#define INF 9876543
using namespace std;

vector<pair<int, int>> edge[MAX];
int Dist[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }
}
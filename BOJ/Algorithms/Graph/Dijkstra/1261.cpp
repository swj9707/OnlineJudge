#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#define MAX 20001
using namespace std;

int V, E;
bool Visit[MAX];
vector<int> adjMatrix[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    for(int c = 0; c < K; c++){
        for(int i = 0; i < MAX; i++) adjMatrix[i].clear();
        cin >> V >> E;
        for(int i = 0; i < E; i++){
            int src, dst;
            cin >> src >> dst;
            adjMatrix[src].push_back(dst);
        }
    }
}
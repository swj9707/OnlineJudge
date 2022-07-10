#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> adj[MAX];
int visited[MAX];
int order = 1;

void DFS(int start){
    visited[start] = order++;
    for(int i = 0; i < adj[start].size(); i++){
        int next = adj[start][i];
        if(visited[next] != 0){
            continue;
        }
        DFS(next);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, R;
    cin >> N >> M >> R;
    for(int i = 0; i < M; i++){
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }
    for(int i = 1; i <= N; i++){
        sort(adj[i].begin(), adj[i].end(), less<int>());
    }
    DFS(R);
    for(int i = 1; i <= N; i++){
        cout << visited[i] << '\n';
    }
}
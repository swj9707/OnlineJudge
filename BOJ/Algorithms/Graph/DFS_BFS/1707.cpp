#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 20001

using namespace std;

vector<int> graph[MAX];
int visited[MAX]; // 

void initSet() {
    for(int i = 0; i < MAX; i++) graph[i].clear();
	memset(visited, 0, sizeof(visited));
}

void BFS(int X){
	queue<int> Q;
	Q.push(X);
	int color = 1;
	while(!Q.empty()){
		int x = Q.front();
		visited[X] = color;
		Q.pop();
		color *= -1;
		for(int i = 0; i < graph[x].size(); i++){
			int nx = graph[x][i];
			if(visited[nx] == 0){
				Q.push(nx);
				visited[nx] = color;
			}
		}
	}
}

void DFS(int X, int color){
	visited[X] = color;
	for(int i = 0; i < graph[X].size(); i++){
		int nx = graph[X][i];
		if(visited[nx] == 0){
			DFS(nx, color * (-1));
		}
	}
}

bool check(int V){
	for(int i = 1; i <= V; i++){
		for(int j = 0; j < graph[i].size(); j++){
			int next = graph[i][j];
			if(visited[i] == visited[next]) return true;	
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int K, V, E;
	cin >> K;
	for(int tc = 0; tc < K; tc++){
		cin >> V >> E;
		initSet();
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for(int i = 1; i < V; i++){
			if(visited[i] == 0) DFS(i, 1);
		}
		if(check(V)) cout << "NO\n";
		else cout << "YES\n";
	}
}
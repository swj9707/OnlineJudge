#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 20001

using namespace std;

vector<int> graph[MAX];
bool visited[MAX];

void initSet() {
	memset(graph, 0, sizeof(graph));
	memset(visited, false, sizeof(visited));
}

void bfs(int V) {
	queue<int> q;
	int 
}



int main() {
	int K, V, E;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		
		for (int j = 0; j < E; j++) {
			int v, e;
			cin >> v >> e;
		}
	}
	
}
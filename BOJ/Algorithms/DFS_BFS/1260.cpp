#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;

int N, M, V;
int matrix[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int a) {
	cout << a << " ";
	for (int i = 1; i <= N; i++) {
		if (matrix[a][i] && !visited[i]) {
			visited[i] = 1;
			DFS(i);
		}
	}
}
void BFS(int a) {
	q.push(a);
	visited[a] = 1;
	while (!q.empty()) {
		a = q.front();
		q.pop();
		cout << a << " ";
		for (int i = 1; i <= N; i++) {
			if (matrix[a][i] && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}
int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		matrix[A][B] = 1;
		matrix[B][A] = 1;
	}
	visited[V] = 1;
	DFS(V);
	cout << '\n';
	memset(visited, false, sizeof(visited));
	BFS(V);
}

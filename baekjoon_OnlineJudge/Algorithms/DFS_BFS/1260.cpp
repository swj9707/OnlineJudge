#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}
void DFS(int * visit_list, int ** matrix,int N, int V) {
	visit_list[V] = 1;
	cout << V << " ";
	for (int i = 1; i < N + 1; i++) {
		if (visit_list[i] == 0 && matrix[V][i] == 1) DFS(visit_list, matrix, i, V);
	}
}

void BFS(int * visit_list, int ** matrix,int N, int V) {
	queue<int> q;
	q.push(V);
	visit_list[V] = 0;
	while (!q.empty()) {
		V = q.front();
		q.pop();
		cout << V << " ";
		for (int i = 1; i < N + 1; i++) {
			if (visit_list[i] == 1 && matrix[V][i] == 1) {
				q.push(i);
				visit_list[i] = 0;
			}
		}
	}
}

int main() {
	init();
	int N, M, V;
	cin >> N >> M >> V;
	int matrix[N + 1][N + 1] = { 0, };
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A, B;
		matrix[A][B] = 1;
		matrix[B][A] = 1;
	}
	int visit_list[N + 1] = { 0, };
	DFS(visit_list, matrix, N, V);
	cout << '\n';
	BFS(visit_list, matrix, N, V);
}
#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int matrix[MAX];
bool visit[MAX];

void dfs(int V) {
	if (V == M) return;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			matrix[V] = i;
			dfs(V + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	dfs(0);
	for (int i = 0; i < M; i++) {
		cout << matrix[i] << ' ';
	}
	cout << '\n';
}
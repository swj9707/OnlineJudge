#include <iostream>
#include <queue>
#define MAX 51;

using namespace std;

int matrix[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void bfs(int x, int y) {
	queue< pair<int , int> > q;
	q.push(make_pair(x, y));
	matrix[x][y] = 0;
	while (!q.empty()) {
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
			if (matr)
		}
	}
}

int main() {
	init();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int M, N;
		cin >> M >> M;
		matrix[M][N] = 1;
	}
}
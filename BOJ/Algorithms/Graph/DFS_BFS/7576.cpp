#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int matrix[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N;

queue<pair<int, int>> Q;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void BFS() {
	while (!Q.empty()) {
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();
		visit[y][x] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visit[ny][nx] && matrix[ny][nx] == 0) {
				visit[ny][nx] = true;
				matrix[ny][nx] = matrix[y][x] + 1;
				Q.push({ ny, nx });
			}
		}
	}
}

int main() {
	init();
	cin >> M >> N;
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> matrix[i][j];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 1) Q.push({ i, j });
		}
	}
	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
			if (result < matrix[i][j]) {
				result = matrix[i][j];
			}
		}
	}
	cout << result - 1 << '\n';
	return 0;
}

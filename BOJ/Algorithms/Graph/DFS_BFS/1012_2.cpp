#include <iostream>
#include <queue>
#include <cstring>
#define MAX 50

using namespace std;

int matrix[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N, K;

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void initData() {
	for (int i = 0; i < MAX; i++) memset(matrix[i], 0, sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++) memset(check[i], false, sizeof(bool) * MAX);
}

void BFS(int X, int Y) {
	queue< pair<int, int> > Q;
	Q.push({ X, Y });
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		check[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !check[nx][ny] && matrix[nx][ny] == 1) {
				check[nx][ny] = true;
				Q.push({ nx, ny });
			}
		}
	}
}

int main() {
	initSet();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		initData();
		int result = 0;
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			matrix[X][Y] = 1;
		}
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (matrix[j][k] == 1 && !check[j][k]) {
					BFS(j, k);
					result += 1;
				}
			}
		}
		cout << result << '\n';
	}
}
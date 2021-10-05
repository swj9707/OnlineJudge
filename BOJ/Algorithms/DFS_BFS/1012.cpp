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
}

bool DFS(int X, int Y) {
	if (X < 0 || X >= M || Y < 0 || Y >= N) return false;
	if (matrix[X][Y] == 1) {
		matrix[X][Y] = 0;
		for (int i = 0; i < 4; i++) {
			int x = X + dx[i];
			int y = Y + dy[i];
			DFS(x, y);
		}
		return true;
	}
	return false;
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
				if (DFS(j, k) == true) {
					result += 1;
				}
			}
		}
		cout << result << '\n';
	}
}
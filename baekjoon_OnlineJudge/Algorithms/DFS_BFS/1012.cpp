#include <iostream>
#define MAX 50;

using namespace std;

int matrix[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int M, N, K;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void bfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		if (matrix[nx][ny] && !check[nx][ny]) {
			check[nx][ny] = 1;

		}
	}
}

int main() {
	init();
	int T;
	cin >> T;
	cin >> M >> N >> K;
	for (int i = 0; i < T; i++) {
		int X, Y;
		cin >> X >> Y;
		matrix[X][Y] = 1;
	}
}
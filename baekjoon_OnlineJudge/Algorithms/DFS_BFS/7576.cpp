#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int matrix[MAX][MAX];
bool visit[MAX][MAX];

int dx = { 1, -1, 0, 0 };
int dy = { 0, 0, 1, -1 };

int M, N;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int BFS(int X, int Y) {
	queue<pair<int, int>> Q;
	int result = 0;
	Q.push({ X, Y });
	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		visit[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N && !check[nx][ny] && matrix[nx][ny] == 0) {
				visit[nx][ny] = true;
				Q.push({ nx, ny });
			}
		}
		result += 1;
	}
	return result;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) cin >> matrix[i][j];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			
		}
	}

}

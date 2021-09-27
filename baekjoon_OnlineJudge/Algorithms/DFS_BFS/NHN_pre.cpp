#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#define MAX 10
using namespace std;

int MATRIX[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int BFS(int X, int Y, int N) {
	deque< pair<int, int, > > dq;
	dq.push_back({ X, Y });
	int result = 1;
	while (!dq.empty()) {
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		visit[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny] && MATRIX[nx][ny] == 1) {
				visit[nx][ny] = true;
				dq.push_back({ nx,ny });
				result += 1;
			}
		}
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> MATRIX[i][j];
	}
	vector<int> result;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MATRIX[i][j] == 1 && !visit[i][j]) {
				int data = BFS(i, j, N);
				result.push_back(data);
			}
		}
	}
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << '\n';
}
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int answer = 0;
void check_bfs(vector<vector<int>>& v) {
	queue<pair<int, int>> q;

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 2)
				q.emplace(i, j);
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x > -1 && next_x < v.size() && next_y > -1 && next_y < v[x].size() &&
				v[next_x][next_y] == 0) {
				q.emplace(next_x, next_y);
				v[next_x][next_y] = 2;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 0)
				cnt++;
		}
	}
	answer = max(answer, cnt);
}

void dfs(vector<vector<int>> v, int x, int y, int cnt){
	v[x][y] = 1;

	if (cnt == 0) {
		check_bfs(v);
		return;
	}

	for (int i = x; i < v.size(); i++) {
		for (int j = 0; j < v[x].size(); j++) {
			if (v[i][j] == 0)
				dfs(v, i, j, cnt - 1);
		}
	}
}

int main() {
	int N, a, b, M;
	
	cin >> N >> M;
	
	vector<vector<int>> v(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++)
			scanf("%d", &v[i][j]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0)
				dfs(v, i, j, 2);
		}
	}
	
	cout << answer << endl;
	return 0;
}
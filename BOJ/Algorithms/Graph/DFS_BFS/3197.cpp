#include <iostream>
#include <queue>
#include <vector>
#define MAX 1500
using namespace std;

int R, C;
int Swan_index[2][2];
bool Meet = false;
char arr[MAX][MAX];
bool visit[MAX][MAX];
queue <pair<int, int>> water;
queue <pair<int, int>> water_ice;
queue <pair<int, int>> swan;
queue <pair<int, int>> swan_ice;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Swan_BFS() {
	while (!swan.empty() && !Meet) {
		int x = swan.front().first; int y = swan.front().second;
		swan.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (visit[nx][ny]) continue;
			if (arr[nx][ny] == '.') {
				visit[nx][ny] = true; swan.push(make_pair(nx, ny));
			}
			else if (arr[nx][ny] == 'L') {
				visit[nx][ny] = true;  Meet = true; break;
			}
			else if (arr[nx][ny] == 'X') {
				visit[nx][ny] = true; swan_ice.push(make_pair(nx, ny));
			}
		}
	}
}

void Water_BFS() {
	while (!water.empty()) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (arr[nx][ny] == 'X') {
				arr[nx][ny] = '.';
				water_ice.push(make_pair(nx, ny));
			}
		}
	}
}

void memset_arr() {
	while (!water_ice.empty()) water_ice.pop();
	while (!swan_ice.empty()) swan_ice.pop();
}

void BFS(){
    int Day = 0;
	swan.push(make_pair(Swan_index[0][0], Swan_index[0][1]));
	visit[Swan_index[0][0]][Swan_index[0][1]] = true;
	while (!Meet) {
		Swan_BFS();
		if (Meet) break;
		Water_BFS();
		swan = swan_ice; water = water_ice;
		memset_arr();
		Day++;
	}
	cout << Day;	
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> R >> C;

	int n = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 'X') water.push(make_pair(i, j));
			if (arr[i][j] == 'L') {
				Swan_index[n][0] = i; Swan_index[n][1] = j;
				n++;
			}
		}
	}
	BFS();
	return 0;
}
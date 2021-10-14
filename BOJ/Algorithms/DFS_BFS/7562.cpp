#include <iostream>
#include <cstring>
#include <queue>
#define MAX 301

using namespace std;

int MATRIX[MAX][MAX];
bool Visit[MAX][MAX];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int N;
int sourceX, sourceY;
int destX, destY;

queue<pair<int, int>> Q;

void initData(){
	memset(Visit, false, sizeof(Visit));
	memset(MATRIX, 0, sizeof(MATRIX));
	while(!Q.empty()) Q.pop();
}

void BFS(int X, int Y){
	Q.push({X, Y});
	Visit[X][Y] = true;
	while (!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		if(x == destX && y == destY){
			cout << MATRIX[x][y] << "\n";
			return;
		}
		for(int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < N && ny >= 0 && ny < N && !Visit[nx][ny]){
				Visit[nx][ny] == true;
				MATRIX[nx][ny] = MATRIX[x][y] + 1;
				Q.push({nx, ny});
			}
		}
	}
}


int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		initData();
		cin >> N;
		cin >> sourceX >> sourceY;		
		cin >> destX >> destY;
		BFS(sourceX, sourceY);
	}
}
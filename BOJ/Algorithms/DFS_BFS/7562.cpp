#include <iostream>
#include <cstring>
#include <deque>
#define MAX 301

using namespace std;

int N;
int sourceX, sourceY;
int destX, destY;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
}

int BFS(int X, int Y, bool ** Visit){
	int result = 0;
	deque<pair<int, int>> Q;
	Q.push_back({X, Y});
	Visit[X][Y] = true;
	while (!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop_front();
		if(x == destX && y == destY){
			return result;
		}
		for(int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < N && ny >= 0 && ny < N && !Visit[nx][ny]){
				Visit[nx][ny] == true;
				result += 1;
				Q.push_back({nx, ny});
			}
		}
	}
}


int main(){
	initSet();
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N;
		bool ** VISIT;
		VISIT = new bool * [N];
		for(int j = 0; j < N; j++) VISIT[j] = new bool[N];
		cin >> sourceX >> sourceY;		
		cin >> destX >> destY;
		int result = BFS(sourceX, sourceY, VISIT);
		cout << result << '\n';
		for(int j = 0; j < N; j++) delete [] VISIT[j];
		delete [] VISIT;
	}
}

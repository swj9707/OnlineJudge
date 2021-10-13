#include <iostream>
#include <cstring>
#include <deque>
#define MAX 301

using namespace std;

bool Visit[MAX][MAX];
int N;
int sourceX, sourceY;
int destX, destY;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

deque<pair<int, int>> Q;

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
}

void initData(){
	memset(Visit, false, sizeof(Visit));
	Q.clear();
}

int BFS(int X, int Y){
	int result = 0;
	Q.push_back({X, Y});
	Visit[X][Y] = true;
	while (!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		result += 1;
		Q.pop_front();
		for(int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 0 && nx < N && ny >= 0 && ny < N && !Visit[nx][ny]);
		}

	}
	

}

int main(){
	initSet();
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

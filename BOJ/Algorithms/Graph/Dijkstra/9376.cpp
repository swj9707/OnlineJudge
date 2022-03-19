#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 987654
using namespace std;

char MATRIX[MAX][MAX];
int Dist[3][MAX][MAX];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<pair<int, int>> prisoner;
vector<pair<int, int>> doors;

void init(){
	prisoner.clear();
	for(int i = 0; i < MAX; i++){
		fill_n(MATRIX, MAX, '.');
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < MAX; j++){
			fill_n(Dist[i][j], MAX, INF);
		}
	}
}

void Dijkstra(int pos,int startX, int startY, int N, int M){
	priority_queue<pair<int, pair<int, int>>> PQ;
	PQ.push({0, {startX, startY}});
	Dist[pos][startX][startY] = 0;
	while(!PQ.empty()){
		int cost = -PQ.top().first;
		int X = PQ.top().second.first;
		int Y = PQ.top().second.second;
		PQ.pop();
		if(Dist[pos][X][Y] < cost) continue;
		for(int i = 0; i < 4; i++){
			int nx = X + dx[i];
			int ny = Y + dy[i];
			if(nx >= 0 && nx <= N && ny >= 0 && ny <= M && MATRIX[nx][ny] != '*'){
				if(MATRIX[nx][ny] == '#') cost++;
				if(Dist[pos][nx][ny] > cost){
					PQ.push({cost, {nx, ny}});
					Dist[pos][nx][ny] = cost;
				}
			}
		}
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--){
		init();
		int N, M; cin >> N >> M;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++) {
				cin >> MATRIX[i][j];
				if(MATRIX[i][j] == '$') prisoner.push_back({i, j});
				else if(MATRIX[i][j] == '#') doors.push_back({i, j});
			}
		}
		Dijkstra(0, 0, 0, N, M);
		Dijkstra(1, prisoner[0].first, prisoner[0].second, N, M);
		Dijkstra(2, prisoner[1].first, prisoner[1].second, N, M);
	}

}
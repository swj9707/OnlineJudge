#include <iostream>
#include <vector>
#include <queue>
#define MAX 102
#define INF 987654

using namespace std;

int N, M;
char MATRIX[MAX][MAX];
int Dist[3][MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0 ,0};
vector<pair<int, int>> prisoner;

void init(){
	prisoner.clear();
	for(int i = 0; i < MAX; i++){
		fill_n(MATRIX[i], MAX, '.');
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < MAX; j++){
			fill_n(Dist[i][j], MAX, INF);
		}
	}
}
void Dijkstra(int X, int Y, int Pos){
	priority_queue<pair<int, pair<int, int>>> PQ;
	PQ.push({0, {X, Y}});
	Dist[Pos][X][Y] = 0;
	while (!PQ.empty()){
		int x = PQ.top().second.first;
		int y = PQ.top().second.second;
		int cost = -PQ.top().first;
		PQ.pop();
		if(Dist[Pos][x][y] < cost) continue;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			int curCost = cost;
			if(nx >= 0 && nx <= N+1 && ny >= 0 && ny <= M+1 && MATRIX[nx][ny] != '*'){
				if(MATRIX[nx][ny] == '#') curCost++;
				if(Dist[Pos][nx][ny] > curCost){
					PQ.push({-curCost, {nx, ny}});
					Dist[Pos][nx][ny] = curCost;
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
		cin >> N >> M;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++) {
				cin >> MATRIX[i][j];
				if(MATRIX[i][j] == '$') prisoner.push_back({i, j});
			}
		}
		Dijkstra(0, 0, 0);
		Dijkstra(prisoner[0].first, prisoner[0].second, 1);
		Dijkstra(prisoner[1].first, prisoner[1].second, 2);		
		int minimum = 99999;
		int cost = 99999;
		for(int i = 0; i <= N+1; ++i){
			for(int j = 0; j <= N+1; ++j){
				if(MATRIX[i][j] != '*'){
					cost = Dist[0][i][j] + Dist[1][i][j] + Dist[2][i][j];
					if(MATRIX[i][j] == '#') cost -= 2;
					minimum = min(minimum, cost);
				}
			}
		}
		cout << minimum << '\n';
	}
}
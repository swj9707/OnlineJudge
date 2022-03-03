#include <iostream>
#include <queue>
#include <cstring>
#define MAX 126
#define INF 9876543
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int MATRIX[MAX][MAX];
int Dist[MAX][MAX];

void initSet(){
    for(int i = 0; i < MAX; i++) memset(MATRIX[i], 0, sizeof(MATRIX[i]));
    for(int i = 0; i < MAX; i++) memset(Dist[i], INF, sizeof(Dist[i]));
}

int Dijkstra(int N){
    priority_queue<pair<int, pair<int, int>>> PQ;
    Dist[1][1] = MATRIX[1][1];
    PQ.push({-Dist[1][1], {1, 1}});
    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int X = PQ.top().second.first;
        int Y = PQ.top().second.second;
        PQ.pop();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx > 0 && nx <= N && ny > 0 && ny <= N){
                if(Dist[nx][ny] > MATRIX[nx][ny] + Cost){
                    Dist[nx][ny] = MATRIX[nx][ny] + Cost;
                    PQ.push({-Dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    return Dist[N][N];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int testCase = 1;
    while(testCase++){
        initSet();
        cin >> N;
        if(N == 0) break;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++) cin >> MATRIX[i][j];
        }
        int result = Dijkstra(N);
        cout << "Problem " << testCase-1 << ": " << result << '\n';
    }
}
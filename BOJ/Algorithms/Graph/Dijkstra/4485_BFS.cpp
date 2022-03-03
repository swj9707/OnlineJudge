#include <iostream>
#include <queue>
#include <cstring>
#define MAX 126
#define INF 9876543
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int MATRIX[MAX][MAX];
int Visit[MAX][MAX];

void initSet(){
    for(int i = 0; i < MAX; i++) memset(MATRIX[i], 0, sizeof(MATRIX[i]));
    for(int i = 0; i < MAX; i++) memset(Visit[i], INF, sizeof(Visit[i]));
}

int BFS(int N){
    queue<pair<int, int>> Q;
    Visit[1][1] = MATRIX[1][1];
    Q.push({1, 1});
    while(!Q.empty()){
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx > 0 && nx <= N && ny > 0 && ny <= N){
                if(Visit[nx][ny] > Visit[X][Y] + MATRIX[nx][ny]){
                    Visit[nx][ny] = Visit[X][Y] + MATRIX[nx][ny];
                    Q.push({nx, ny});
                }
            }
        }
    }
    return Visit[N][N];
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
        int result = BFS(N);
        cout << "Problem " << testCase-1 << ": " << result << '\n';
    }
}
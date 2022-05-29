#include <iostream>
#include <queue>
#include <cstring>
#define MAX 51
using namespace std;

char MATRIX[MAX][MAX];
int Visit[MAX][MAX];
int dx[4] = {1, -1 ,0 ,0};
int dy[4] = {0, 0, 1, -1};

void clear(int N, int M){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            Visit[i][j] = -1;
        }
    }
}

int BFS(int x, int y, int N, int M){
    queue<pair<int, int>> Q;
    Visit[x][y] = 0;
    Q.push({x, y});
    int result = 0;
    while(!Q.empty()){
        int X = Q.front().first;
        int Y = Q.front().second;
        result = max(result, Visit[X][Y]);
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx > 0 && nx <= N && ny > 0 && ny <= M && Visit[nx][ny] == -1 && MATRIX[nx][ny] == 'L'){
                Visit[nx][ny] = Visit[X][Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    int answer = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> MATRIX[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(MATRIX[i][j] == 'L'){
                int result = BFS(i, j, N, M);
                answer = max(result, answer);
                clear(N, M);
            }
        }
    }

    cout << answer << '\n';
}
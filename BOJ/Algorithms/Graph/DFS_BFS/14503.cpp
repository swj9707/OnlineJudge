#include <iostream>

using namespace std;

int N, M;
int answer = 0;
int MATRIX[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int X, int Y, int dir){
    if(MATRIX[X][Y] == 0){
        MATRIX[X][Y] = 2;
        answer++;
    }

    for(int i = 0; i < 4; i++){
        int nd = (dir + 3 - i) % 4;
        int nx = X + dx[nd];
        int ny = Y + dy[nd];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        if(MATRIX[nx][ny] == 0) DFS(nx, ny, nd);
    }

    int nd = (dir + 2) % 4;
    int nx = X + dx[nd];
    int ny = Y + dy[nd];

    if(MATRIX[nx][ny] == 1){
        cout << answer << '\n';
        exit(0);
    }
    DFS(nx, ny, nd);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> MATRIX[i][j];
    }
    DFS(r, c, d);
}
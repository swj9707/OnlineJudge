#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int MATRIX[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


bool BFS(int y, int x, int N, int M){
    queue<pair<int, int>> Q;
    Q.push({y, x});
    visited[y][x] = true;
    while(!Q.empty()){
        int Y = Q.front().first;
        int X = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int ny = Y + dy[i];
            int nx = X + dx[i];
            if(ny > 0 && ny <= N && nx > 0 && nx <= M && !visited[ny][nx] && MATRIX[ny][nx] == 0){
                if(ny == N){
                    return true;
                } else {
                    visited[ny][nx] = true;
                    Q.push({ny, nx});
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string tmp; cin >> tmp;
        for(int j = 0; j < M; j++){
            if(tmp[j] == '0'){
                MATRIX[i][j+1] = 0;
            } else {
                MATRIX[i][j+1] = 1;
            }
        }
    }

    for(int i = 1; i <= M; i++){
        if(MATRIX[1][i] == 0 && !visited[1][i]){
            bool result = BFS(1, i, N, M);
            if(result) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}

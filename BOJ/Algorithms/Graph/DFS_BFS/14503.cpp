#include <iostream>

using namespace std;

int MATRIX[50][50];
bool visit[50][50];

int N, M;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void DFS(int r, int c, int d, int sum){
    for(int i = 0; i < 4; i++){
        int nd = (d + 3 - i) % 4;
        int nr = r + dr[nd];
        int nc = c + dc[nd];

        if(nr < 0 || nr >= N || nc < 0 || nc >= M || MATRIX[nr][nc] == 1) continue;
        if(!visit[nr][nc] && MATRIX[nr][nc] == 0){
            visit[nr][nc] == true;
            DFS(nr, nc, nd, sum+1);
        }

        int backIdx = d + 2 < 4 ? d + 2 : d - 2;
        int backr = r + dr[backIdx];
        int backc = c + dc[backIdx];
        if(0 <= backr && backr <= N && 0 <= backc && backc <= M){
            if(MATRIX[backr][backc] == 0){
                DFS(backr, backc, d, sum);
            }
            else{
                cout << sum << '\n';
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MATRIX[i][j];
            visit[i][j] = false;
        }
    }
    visit[r][c] = true;
    DFS(r, c, d, 1);
    return 0;
}
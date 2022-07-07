#include <bits/stdc++.h>
#define MAX 101
using namespace std;

char MATRIX[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int BFS(int Y, int X, int N, int M, char color){
    queue<pair<int, int>> Q;
    Q.push({Y, X});
    visit[Y][X] = true;
    int result = 1;
    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny > 0 && ny <= M && nx > 0 && nx <= N && MATRIX[ny][nx] == color && !visit[ny][nx]){
                visit[ny][nx] = true;
                result += 1;
                Q.push({ny, nx});
            }
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    int blue = 0, white = 0;
    for(int Y = 1; Y <= M; Y++){
        for(int X = 1; X <= N; X++){
            cin >> MATRIX[Y][X];
        }
    }

    for(int Y = 1; Y <= M; Y++){
        for(int X = 1; X <= N; X++){
            if(!visit[Y][X]){
                int result = BFS(Y, X, N, M, MATRIX[Y][X]);
                if(MATRIX[Y][X] == 'B'){
                    blue += result * result;
                } else {
                    white += result * result;
                }
            }
        }
    }
    cout << white << " " << blue << '\n';
}
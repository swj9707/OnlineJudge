#include <iostream>
#define MAX 20
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer = 0;
int R, C;
bool visit[26];
char MATRIX[MAX][MAX];
void DFS(int X, int Y, int count){
    answer = max(answer, count);
    for(int i = 0; i < 4; i++){
        int nx = X + dx[i];
        int ny = Y + dy[i];
        if(0 <= nx && nx < R && 0 <= ny && ny < C && !visit[MATRIX[nx][ny] - 'A']){
            visit[MATRIX[nx][ny] - 'A'] = true;
            DFS(nx, ny, count + 1);
            visit[MATRIX[nx][ny] - 'A'] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cin >> MATRIX[i][j];
    }
    visit[MATRIX[0][0] - 'A'] = true;
    DFS(0, 0, 1);
    cout << answer << '\n';
}
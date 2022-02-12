#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int N;
char MATRIX[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void initSet(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) visit[i][j] = false;
    }
}

void BFS(int X, int Y){
    queue<pair<int, int>> Q;
    Q.push({X, Y});
    visit[X][Y]= true;
    char currentColor = MATRIX[X][Y];
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny] && MATRIX[nx][ny] == currentColor){
                visit[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> MATRIX[i][j];
    }
    int result1 = 0, result2 = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j]){
                BFS(i, j);
                result1 += 1;
            }
        }
    }
    initSet();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(MATRIX[i][j] == 'G') MATRIX[i][j] = 'R';
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visit[i][j]){
                BFS(i, j);;
                result2 += 1;
            }
        }
    }
    cout << result1 << " " << result2 << '\n';
}
#include <iostream>
#include <deque>
#define MAX 101
using namespace std;

int N, M, K;
int Matrix[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(int X, int Y){
    int result = 0;
    deque<pair<int, int>> Q;
    Q.push_back({X, Y});
    visit[X][Y] = true;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop_front();
        result += 1;
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx <= N && ny >= 0 && ny <= M && !visit[nx][ny] && Matrix[nx][ny] == 1){
                visit[nx][ny] = true;
                Q.push_back({nx, ny});
            }
        }
    }
    return result;
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        int r, c;
        cin >> r >> c;
        Matrix[r][c] = 1;
    } 
    int Answer = -9999;
    for(int i = 0 ; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(!visit[i][j] && Matrix[i][j] == 1){
                int tmp = BFS(i, j);
                if(Answer < tmp) Answer = tmp;
            }
        }
    }
    cout << Answer << '\n';
    return 0;
}
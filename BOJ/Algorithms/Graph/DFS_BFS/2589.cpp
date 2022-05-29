#include <iostream>
#include <deque>
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
            Visit[i][j] = 0;
        }
    }
}

int BFS(int x, int y, int N, int M){
    deque<pair<int, int>> DQ;
    DQ.push_back({x, y});
    int result = 0;
    while(!DQ.empty()){
        int X = DQ.front().first;
        int Y = DQ.front().second;
        result = max(result, Visit[X][Y]);
        DQ.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx > 0 && nx <= N && ny > 0 && ny <= M && Visit[nx][ny] == 0 && MATRIX[nx][ny] != 'W'){
                Visit[nx][ny] = Visit[X][Y] + 1;
                DQ.push_back({nx, ny});
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
                clear(N, M);
                int result = BFS(i, j, N, M);
                answer = max(result, answer);
            }
        }
    }

    cout << answer << '\n';
}
#include <iostream>
#include <deque>
#include <tuple>
#define MAX 100
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M;

int MATRIX[MAX][MAX];
bool Visit[MAX][MAX];

void BFS(){
    deque<tuple<int, int, int>> DQ;
    DQ.push_back({0, 0, 0});
    while(!DQ.empty()){
        int X, Y, count;
        tie(X, Y, count) = DQ.front();
        Visit[X][Y] = true;
        if(X == N-1 && Y == M-1){
            cout << count << '\n';
            return;
        }
        DQ.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !Visit[nx][ny]){
                Visit[nx][ny] = true;
                if(MATRIX[nx][ny] == 0) DQ.push_back({nx, ny, count});
                else DQ.push_back({nx, ny, count + 1});
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MATRIX[i][j];
        }
    }
    BFS();
}
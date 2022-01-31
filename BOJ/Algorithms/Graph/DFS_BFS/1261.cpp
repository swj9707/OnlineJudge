#include <iostream>
#include <deque>
#define MAX 101
using namespace std;

int M, N;
int MATRIX[MAX][MAX];
bool Visit[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void BFS(){
    deque<pair<int, pair<int, int>>> DQ;//count, X, Y
    DQ.push_back({0,{1,1}});
    Visit[1][1] = true;
    while(!DQ.empty()){
        int X = DQ.front().second.first;
        int Y = DQ.front().second.second;
        int count = DQ.front().first;
        if(X == M && Y == N){
            cout << count << '\n';
            return;
        }
        Visit[X][Y] = true;
        DQ.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx >= 1 && nx <= M && ny >= 1 && ny <= N && !Visit[nx][ny]){
                if(MATRIX[nx][ny] == 1) DQ.push_back({count+1, {nx,ny}});
                else DQ.push_back({count, {nx,ny}});
                Visit[nx][ny] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i = 1; i <= N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++){
            if(tmp[j] != '0') MATRIX[i][j+1] = 1;
        }
    }
    

    BFS();
}
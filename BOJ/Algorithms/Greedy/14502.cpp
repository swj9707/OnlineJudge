#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N, M;
int answer = 0;
void BFS(vector<vector<int>> & vec){
    queue<pair<int, int>> Q;
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vec[i][j] == 2) Q.push({i, j});
        }
    }
    while(!Q.empty()){
        int X = Q.front().first;
        int Y = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && vec[nx][ny] == 0){
                vec[nx][ny] = 2;
                Q.push({nx, ny});
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vec[i][j] == 0) count++;
        }
    }
    answer = max(answer, count);
}

void DFS(vector<vector<int>> vec, int x, int y, int count){
    vec[x][y] = 1;
    if(count == 0){
        BFS(vec);
        return;
    }
    for(int i = x ; i < N ; i++){
        for(int j = 0; j < M; j++){
            if(vec[i][j] == 0) DFS(vec, i, j, count -1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<vector<int>> vec(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> vec[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vec[i][j] == 0) DFS(vec, i, j, 2);
        }
    }
    cout << answer << '\n';
    return 0;
}
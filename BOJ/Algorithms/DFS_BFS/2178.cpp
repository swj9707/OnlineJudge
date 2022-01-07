#include <iostream>
#include <deque>
#define MAX 101
using namespace std;

int N, M;
bool visit[MAX][MAX];
int MATRIX[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(int x, int y){
    deque<pair<int, int>> dq;
    dq.push_back({x, y});
    while(!dq.empty()){
        int X = dq.front().first;
        int Y = dq.front().second;
        dq.pop_front();
        visit[X][Y] = true;
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && !visit[nx][ny]){
                visit[nx][ny] = true;
                dq.push_back({nx, ny});
                MATRIX[nx][ny] = MATRIX[X][Y] + 1;
            }
        }
    }
    return MATRIX[N-1][M-1] + 1;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0 ; j < M; j++){
            if(tmp[j] == '1') visit[i][j] = false;
            else visit[i][j] = true;
        }
        cout << "wtf\n";
    }
    int result = BFS(0, 0);
    cout << result << '\n';
}
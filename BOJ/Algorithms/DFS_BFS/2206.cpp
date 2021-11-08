#include <iostream>
#include <deque>
#include <tuple>
#define MAX 1000

using namespace std;

int N, M;
int MATRIX[MAX][MAX];
int visit[MAX][MAX][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(){
    deque<tuple<int, int, int>> Q;
    Q.push_back({0, 0, 1});
    visit[0][0][1];
    while(!Q.empty()){
        int X , Y, block;
        tie(X, Y, block) = Q.front();
        Q.pop_front();
        cout << X << " " << Y << " " << block << '\n';
        if(X == N - 1 && Y == M - 1){
            cout << visit[X][Y][block] << "\n";
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(MATRIX[nx][ny] == 1 && block == 1){
                    visit[nx][ny][block - 1] = visit[X][Y][block] + 1;
                    Q.push_back({nx, ny, block - 1});
                }
                if(MATRIX[nx][ny] == 1 && visit[nx][ny][block] == 0){
                    visit[nx][ny][block] = visit[nx][ny][block] + 1;
                    Q.push_back({nx, ny, block});
                }
            }
        }
    }
    cout << "-1\n";
    return;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string tmp; cin >> tmp;
        for(int j = 0; j < M; j++) MATRIX[i][j] = tmp[j] - '0';
    }
    BFS();
}
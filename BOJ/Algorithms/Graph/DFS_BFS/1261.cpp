#include <iostream>
#include <deque>
#define MAX 101
#define INF 98765432

using namespace std;

int M, N;
int MATRIX[MAX][MAX];
int Dist[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Dijkstra(){
    deque<pair<int, int>> DQ;
    DQ.push_back({1, 1});
    Dist[1][1] = 0;

    while(!DQ.empty()){
        int X = DQ.front().first;
        int Y = DQ.front().second;
        DQ.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= M){
                if(MATRIX[nx][ny] == 1){
                    if(Dist[nx][ny] > Dist[X][Y] + 1){
                        Dist[nx][ny] = Dist[X][Y] + 1;
                        DQ.push_back({nx, ny});
                    }
                }
                else{
                        if(Dist[nx][ny] > Dist[X][Y]){
                            Dist[nx][ny] = Dist[X][Y];
                            DQ.push_back({nx, ny});
                        }
                    }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++){
            Dist[i+1][j+1] = INF;
            MATRIX[i+1][j+1] = tmp[j] - '0';
        }
    }
    Dijkstra();
    cout << Dist[N][M] << '\n'; 
}
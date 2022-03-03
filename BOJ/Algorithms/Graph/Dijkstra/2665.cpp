#include <iostream>
#include <deque>
#include <cstring>
#define MAX 51
#define INF 987654
using namespace std;

int MATRIX[MAX][MAX];
int Dist[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void initSet(){
    for(int i = 0; i < MAX; i++) memset(MATRIX[i], 0, sizeof(MATRIX[i]));
    for(int i = 0; i < MAX; i++) memset(Dist[i], INF, sizeof(Dist[i]));
}

void Dijkstra(int N){
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
            if(nx >= 1 && nx <= N && ny >= 1 && ny <= N){
                if(MATRIX[nx][ny] == 0){
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
    initSet();
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < N; j++){
            MATRIX[i+1][j+1] = tmp[j] - '0';
        }
    }
    Dijkstra(N);
    cout << Dist[N][N] << '\n';
}
#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
#define MAX 101
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N;
int Matrix[MAX][MAX];
bool visit[MAX][MAX];

void BFS(int X, int Y, int SafeArea){
    deque<pair<int, int>> Q;
    Q.push_back({X, Y});
    visit[X][Y] = true;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop_front();
        for(int i = 0 ; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(Matrix[nx][ny] >= SafeArea && visit[nx][ny] == false){
                    visit[nx][ny] = true;
                    Q.push_back({nx, ny});
                } 
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    int Min = 9999;
    int Max = -9999;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Matrix[i][j];
            if(Matrix[i][j] > Max) Max = Matrix[i][j];
            if(Matrix[i][j] < Min) Min = Matrix[i][j];
        }
    }
    int safeArea_Max = Min;
    for(int i = Min; i <= Max; i++){
        int tmp = 0;
        memset(visit, false, sizeof(visit));
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(Matrix[j][k] >= i && !visit[j][k]){
                    BFS(j, k,i);
                    tmp += 1;
                }
            }
        }
        if(tmp > safeArea_Max) safeArea_Max = tmp;
    }
    cout << safeArea_Max << '\n';
}

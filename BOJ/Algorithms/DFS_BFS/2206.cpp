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
        if(X == N - 1 && Y == M - 1){
            cout << visit[X][Y][block] << "\n";
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if(nx >= 0 && )
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> MATRIX[i][j];
    }
    BFS();
}
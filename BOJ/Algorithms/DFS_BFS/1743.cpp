#include <iostream>
#include <deque>

#define MAX 101
using namespace std;
int N, M, K;
int Matrix[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(int X, int Y){
    deque<pair<int, int>> Q;
    Q.push_back({X, Y});
    visit[X][Y] = true;
    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;

    }
}

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        int r, c;
        cin >> r >> c;
        Matrix[r][c] = 1;
    }
}
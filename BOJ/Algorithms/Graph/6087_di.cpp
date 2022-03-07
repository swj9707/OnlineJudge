#include <iostream>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;

char MATRIX[MAX][MAX];
int Visit[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> Point;

void BFS(int initX, int initY, int W, int H){
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Visit[initX][initY] = 0;
    for(int i = 0; i < 4; i++) Q.push({{initX, initY},{i, 0}});
    while(!Q.empty()){
        int X = Q.front().first.first;
        int Y = Q.front().first.second;
        int Direction = Q.front().second.first;
        int Count = Q.front().second.second;
        Q.pop();
        for(int i = 0; i <4 ; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            int nextCount = Count;
            if(nx > 0 && nx <= H && ny > 0 && ny <= W && MATRIX[nx][ny] != '*'){
                if(Direction != i) nextCount = Count + 1;
                if(Visit[nx][ny] == -1 || Visit[nx][ny] >= nextCount){
                    Visit[nx][ny] = nextCount;
                    Q.push({{nx, ny}, {i, nextCount}});
                } 
            }
        }
    }
    cout << Visit[Point[1].first][Point[1].second] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int W, H; cin >> W >> H;
    for(int i = 1; i <= H; i++){
        string tmp; cin >> tmp;
        for(int j = 1; j <= W; j++){
            MATRIX[i][j] = tmp[j-1];
            if(MATRIX[i][j] == 'C') Point.push_back({i, j}); 
        }
    }
    for(int i = 0; i < MAX; i++) fill_n(Visit[i], MAX, -1);
    BFS(Point[0].first, Point[0].second, W, H);
}
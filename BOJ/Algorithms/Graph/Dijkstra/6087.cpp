#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
#define INF 987654
using namespace std;

char MATRIX[MAX][MAX];
int Dist[MAX][MAX][4];
vector<pair<int, int>> Points;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct Node{
    pair<pair<int, int>, pair<int, int>> Data;
    Node() {}
    Node(int x, int y, int dir, int cnt) : Data({{cnt, dir},{x, y}}){}
} Node;
struct compare{
    bool operator()(const Node & node1, const Node & node2){
        return node1.Data.first.first > node2.Data.first.first;
    }
};

int Dijkstra(int W, int H){
    priority_queue<pair<pair<int, int>, pair<int, int>>> PQ;
    int X = Points[0].first;
    int Y = Points[0].second;
    for(int i = 0; i < 4; i++){
        int nx = X + dx[i];
        int ny = Y + dy[i];
        if(nx > 0 && nx <= H && ny > 0 && ny <= W && MATRIX[nx][ny] != '*'){
            PQ.push({{0, i}, {nx, ny}});
        }
    }
    while(!PQ.empty()){
        int x = PQ.top().second.first;
        int y = PQ.top().second.second;
        int dir = PQ.top().first.second;
        int cnt = -PQ.top().first.first;
        PQ.pop();
        if(x == Points[1].first && y == Points[1].second) return cnt;
        for(int i = 0; i < 4; i++){
            int nx = x, ny = y;
            if(i != dir){
                nx += dx[i];
                ny += dy[i];
            }
            if(nx > 0 && nx <= H && ny > 0 && ny <= W && MATRIX[nx][ny] != '*'){
                if(MATRIX[nx][ny] == '.'){
                    if(Dist[nx][ny][i] > Dist[x][y][dir] + 1){
                        Dist[nx][ny][i] = Dist[x][y][dir] + 1;
                        PQ.push({{(cnt+1)*(-1), i}, {nx, ny}});
                    }
                }
            }
            if(Dist[nx][ny][dir] > Dist[x][y][dir]){
                Dist[nx][ny][dir] = Dist[x][y][dir];
            }
        }
       
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int W, H; cin >> W >> H;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> MATRIX[i][j];
            if(MATRIX[i][j] == 'C') Points.push_back({i, j});
            for(int k = 0; k < 4; k++) Dist[i][j][k] = INF;
        }
    }
    int answer = Dijkstra(W, H);
    cout << answer << '\n';
}
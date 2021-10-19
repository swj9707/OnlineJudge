#include <iostream>
#include <deque>
#define MAX 101
using namespace std;

typedef struct point{
    int Y;
    int X;
    int Z;
} point;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int MATRIX[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int M, N, H;
deque<point> Q;

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
}

void BFS(){
    while(!Q.empty()){
        int Y = Q.front().Y;
        int X = Q.front().X;
        int Z = Q.front().Z;
        Q.pop_front();
        visit[Y][X][Z] = true;
        for(int i = 0; i < 6; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];
            int nz = Z + dz[i];
            if(ny >= 0 && ny < M && nx >= 0 && nx < N && nz >= 0 && nz < H && !visit[ny][nx][nz] && MATRIX[ny][nx][nz] == 0){
                visit[ny][nx][nz] = true;
                MATRIX[ny][nx][nz] = MATRIX[Y][X][Z] + 1;
                Q.push_back({ny, nx, nz});
            }
        }
    }
}

int main(){
    initSet();
    cin >> M >> N >> H;
    for(int h = 0; h < H; h++){
        for(int y = 0; y < M; y++){
            for(int x = 0; x < N; x++){
                cin >> MATRIX[y][x][h];
                if(MATRIX[y][x][h] == 1){
                    point tmp = {y, x, h};
                    Q.push_back(tmp);
                    visit[y][x][h] = true;
                }
                else if(MATRIX[y][x][h] == -1) visit[y][x][h] = true;
            }
        }
    }
    if(Q.empty()) cout << "-1\n";
    else {
        BFS();
        int result = 0;
        for(int h = 0; h < H; h++){
            for(int y = 0; y < M; y++){
                for(int x = 0; x < N; x++){
                    if(result < MATRIX[y][x][h]) result = MATRIX[y][x][h];
                }
            }
        }
        cout << result -1 << '\n';
    }
}
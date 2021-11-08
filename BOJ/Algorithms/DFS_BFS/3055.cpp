#include <iostream>
#include <deque>
#include <tuple>
#define MAX 50
using namespace std;

char MATRIX[MAX][MAX];
bool Visit[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int R, C;
int dstX, dstY;
//비어있는곳 : . , 물이 차있는 곳 : * , 돌 : X, 비버의 굴 : D, 고슴도치 : S
deque<pair<int, int>> Unit;
deque<pair<int, int>> Water;

void BFS(){
    int count = 0;
    while(!Unit.empty()){
        count++;
        int WaterSize = Water.size();
        while(WaterSize--){
            int X = Water.front().first;
            int Y = Water.front().second;
            Water.pop_front();
            for(int i = 0; i < 4; i++){
                int nx = X + dx[i];
                int ny = Y + dy[i];
                if(nx >= 0 && nx < R && ny >= 0 && ny < C && MATRIX[nx][ny] != 'X' && MATRIX[nx][ny] != 'D' && MATRIX[nx][ny] != '*'){
                    Water.push_back({nx, ny});
                    MATRIX[nx][ny] = '*';
                }
            }
        }
        int UnitSize = Unit.size();
        while(UnitSize--){
            int X = Unit.front().first;
            int Y = Unit.front().second;
            Visit[X][Y] = true;
            if(X == dstX && Y == dstY){
                cout << count - 1 << '\n';
                return;
            }
            Unit.pop_front();
            for(int i = 0; i < 4; i++){
                int nx = X + dx[i];
                int ny = Y + dy[i];
                if(nx >= 0 && nx < R && ny >= 0 && ny < C && MATRIX[nx][ny] != 'X' && MATRIX[nx][ny] != '*' && !Visit[nx][ny]){
                    Unit.push_back({nx, ny});
                    Visit[nx][ny] = true;
                }
            }
        }
    }
    cout << "KAKTUS\n";
    return;
}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cin >> MATRIX[i][j];
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if (MATRIX[i][j] == 'D'){dstX = i; dstY = j;}
            else if (MATRIX[i][j] == 'S') Unit.push_back({i, j});
            else if (MATRIX[i][j] == '*') Water.push_back({i, j});
        }
    }
    BFS();
}
#include <iostream>
#include <deque>
#define MAX 250
using namespace std;

int R, C;
char MATRIX[MAX][MAX];
bool Visit[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int shp, wlf;

void BFS(int Y, int X){
    deque< pair<int, int>> DQ;
    int sheep = 0;
    int wolf = 0;
    DQ.push_back({Y, X});
    Visit[Y][X] = true;
    while(!DQ.empty()){
        int y = DQ.front().first;
        int x = DQ.front().second;
        DQ.pop_front();
        if(MATRIX[y][x] == 'v') wolf += 1;
        else if (MATRIX[y][x] == 'o') sheep += 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < R && nx >= 0 && nx < C && !Visit[ny][nx] && MATRIX[ny][nx] != '#'){
                DQ.push_back({ny, nx});
                Visit[ny][nx] = true;
            }
        }        
    }
    if(sheep != 0 || wolf != 0){
        if(sheep > wolf) shp += sheep;
        else wlf += wolf;
    }
}
int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> MATRIX[i][j];
        }
    }   
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(MATRIX[i][j] != '#' && !Visit[i][j]) BFS(i, j);
        }
    }   
    cout << shp << " " <<wlf<<'\n';  
}
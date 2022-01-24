#include <iostream>
#include <string>
#include <deque>
#include <set>

using namespace std;

int MATRIX[6][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
set <int> result;

void DFS(int X, int Y, int data, int count){
    if(count == 5) {
        result.insert(data);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = X + dx[i];
        int ny = Y + dy[i];
        if(nx >= 1 && nx <= 5 && ny >= 1 && ny <= 5){
            DFS(nx, ny, data * 10 + MATRIX[nx][ny], count + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++) cin >> MATRIX[i][j];
    }
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++) DFS(i, j, MATRIX[i][j], 0);
    }
    cout << result.size() << '\n';
}
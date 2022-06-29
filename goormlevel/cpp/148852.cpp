#include <iostream>
#define MAX 10001
using namespace std;

int MATRIX[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    int answer = 1;
    string tmp; cin >> tmp;
    MATRIX[1][1] = 1;
    int x = 1, y = 1;
    for(auto cmd : tmp){
        int nx = x, ny = y;
        if(cmd == 'E'){
            ny = y - 1;
        } else if (cmd == 'W'){
            ny = y + 1;
        } else if (cmd == 'S'){
            nx = x + 1;
        } else if (cmd == 'N'){
            nx = x - 1;
        }
        if(nx > 0 && nx <= N && ny > 0 && ny <= M){
            MATRIX[nx][ny] = MATRIX[nx][ny] + 1;
            x = nx;
            y = ny;
            
            answer = max(answer, MATRIX[nx][ny]);
        } else {
            MATRIX[x][y] = MATRIX[x][y] + 1;
            answer = max(answer, MATRIX[x][y]);
        }
    }
    cout << answer << '\n';
}
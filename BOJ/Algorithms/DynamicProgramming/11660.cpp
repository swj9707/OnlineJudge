#include <iostream>
#define MAX 1025
using namespace std;

int DP[MAX][MAX];
int MATRIX[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) cin >> MATRIX[i][j];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            DP[i][j] = DP[i - 1][j] + DP[i][j-1] - DP[i - 1][j-1]  + MATRIX[i][j];
        }
    }
    for(int i = 1; i <= M; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = DP[x2][y2] - DP[x1-1][y2] - DP[x2][y1-1] + DP[x1-1][y1-1];
        cout << answer << '\n';
    }
}
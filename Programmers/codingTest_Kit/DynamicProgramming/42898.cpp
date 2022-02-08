#include <string>
#include <vector>
#define MAX 101
using namespace std;

int DP[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    DP[1][1] = 1;
    for(int i = 0; i < puddles.size(); i++){
        DP[puddles[i][1]][puddles[i][0]] = -1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (i == 1 && j == 1) continue;
            if(DP[i][j] == -1) DP[i][j] = 0;
            else{
                DP[i][j] = (DP[i-1][j] + DP[i][j-1]) % 1000000007;
            }
        }
    }
    return DP[n][m];
}
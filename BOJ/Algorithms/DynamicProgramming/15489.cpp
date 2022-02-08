#include <iostream>
#define MAX 31
using namespace std;

int DP[MAX][MAX] = {1};

void init(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) DP[i][j] = 1;
    }
    for(int i = 3; i < MAX; i++){
        for(int j = 1; j <= i; j++){
            if(j != 1 && j != i){
                DP[i][j] = DP[i - 1][j-1] + DP[i-1][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int R, C, W;
    cin >> R >> C >> W;
    int answer = 0;
    for(int i = 0; i < W; i++){
        for(int j = 0; j <= i; j++){
            answer += DP[R+i][C+j];
        }
    }
    cout << answer << '\n';
} 
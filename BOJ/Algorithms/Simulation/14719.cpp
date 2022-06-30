#include <bits/stdc++.h>

using namespace std;

int MATRIX[501][501];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W; cin >> H >> W;
    int answer = 0;
    for(int i = 1; i <= W; i++){
        int N; cin >> N;
        for(int j = 1; j <= N; j++){
            MATRIX[j][i] = 1;
        }
    }

    for(int i = H; i >= 1; i--){
        int l = 0, r = W;
        if(MATRIX[i][l] == 1 && MATRIX[i][r] == 1) break;

        while(MATRIX[i][l] == 0){
            MATRIX[i][l] = -1;
            l++;
        }

        while(MATRIX[i][r] == 0){
            MATRIX[i][r] = -1;
            r--;
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(MATRIX[i][j] == 0) answer++;
        }
    }
    cout << answer << '\n';
}
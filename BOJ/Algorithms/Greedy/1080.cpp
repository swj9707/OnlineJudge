#include <iostream>
#define MAX 50
using namespace std;

int N, M;

int MATRIX_A[MAX][MAX];
int MATRIX_B[MAX][MAX];

void chgData(int x, int y){
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            MATRIX_A[i][j] = 1 - MATRIX_A[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    string tmp;
    int answer = 0;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        for(int j = 0; j < M; j++){
            MATRIX_A[i][j] = tmp[j] - '0';
        }
    }
    for(int i = 0; i < N; i++){
        cin >> tmp;
        for(int j = 0; j < M; j++){
            MATRIX_B[i][j] = tmp[j] - '0';
        }
    }

    for(int i = 0; i < N - 2; i++){
        for(int j = 0 ; j < M - 2; j++){
            if(MATRIX_A[i][j] != MATRIX_B[i][j]){
                chgData(i, j);
                answer++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MATRIX_A[i][j] != MATRIX_B[i][j]){
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
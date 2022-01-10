#include <iostream>
#include <queue>
#include <vector>
#define MAX 501
using namespace std;

int MATRIX[MAX][MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) MATRIX[i][j] = -1;
    }
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        MATRIX[A][B] = 1;
    }
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(MATRIX[i][j] > MATRIX[i][k] + MATRIX[k][j]) MATRIX[i][j] = MATRIX[i][k] + MATRIX[k][j];
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <= N; i++){
        int count = 0;
        for(int j = 1; j <= N; j++){
            if(MATRIX[i][j] != -1 || MATRIX[j][i] != -1) count++;
        }
        cout << count << '\n';
        if(count == N - 1) answer++;
    }
    cout << answer << '\n';
}
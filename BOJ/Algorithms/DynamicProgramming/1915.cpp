#include <iostream>
#define MAX 1001
using namespace std;

int MATRIX[MAX][MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++) MATRIX[i][j+1] = tmp[j] - 48;
    }
    int len = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(MATRIX[i][j] != 0){
                MATRIX[i][j] = min(MATRIX[i-1][j-1], min(MATRIX[i-1][j] , MATRIX[i][j-1])) + 1;
                len = max(MATRIX[i][j], len);
            }
        }
    }
    cout << len * len <<'\n';
    return 0;
}
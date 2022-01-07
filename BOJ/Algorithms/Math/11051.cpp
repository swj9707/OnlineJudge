#include <iostream>
#define MAX 1001
using namespace std;

int DP[MAX][MAX];
int main(){
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(i == j || j == 0){
                DP[i][j] = 1;
                continue;
                //Combination 에서 0번 선택하거나 N번 선택하는 경우는 1을 리턴한다.
            }
            DP[i][j] = (DP[i-1][j] + DP[i-1][j-1]) % 10007;
            //파스칼의 삼각형
        }
    }
    cout << DP[N][K];
    return 0;
}
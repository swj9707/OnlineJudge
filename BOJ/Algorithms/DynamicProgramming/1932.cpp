#include <iostream>
#define MAX 501
using namespace std;

int arr[MAX][MAX];
int dp[MAX][MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 2 ; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }
    int answer = 0;
    for(int i = 1; i <= N; i++) answer = max(answer, dp[N][i]);
    cout << answer << '\n';
}
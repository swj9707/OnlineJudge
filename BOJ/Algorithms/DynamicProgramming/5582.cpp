#include <iostream>
#define MAX 4001
using namespace std;

int DP[MAX][MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string A, B;
    cin >> A >> B;
    DP[0][0] = 0;
    int answer = 0;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            if(A[i] == B[j]){
                if(i == 0 || j == 0) DP[i][j] = 1;
                else DP[i][j] = DP[i - 1][j - 1] + 1;
                answer = max(answer, DP[i][j]);
            }
        }
    }
    cout << answer << '\n';

}
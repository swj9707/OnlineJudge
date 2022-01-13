#include <iostream>
#include <string>
#define MAX 1001

using namespace std;

int DP[MAX][MAX];
string LCS[MAX][MAX];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string A, B;
    cin >> A >> B;
    for(int i = 1; i <= A.length(); i++){
        for(int j = 1; j <= B.length(); j++){
            if(A[i - 1] == B[j - 1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
                LCS[i][j] = LCS[i][j] + LCS[i-1][j-1] + A[i-1];
            }
            else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
                if(LCS[i-1][j].length() > LCS[i][j-1].length()){
                    LCS[i][j] = LCS[i-1][j];
                }
                else{
                    LCS[i][j] = LCS[i][j-1];
                }
            }
        }
    }
    cout << DP[A.length()][B.length()] << "\n" << LCS[A.length()][B.length()];
}
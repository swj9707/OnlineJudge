#include <iostream>
#define MAX 10001
using namespace std;

double DP[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> DP[i];
    double answer = DP[1];

    for(int i = 2; i <= N; i++){
        if(DP[i] * DP[i-1] >= DP[i]){
            DP[i] = DP[i] * DP[i-1];
        }
        answer = max(answer, DP[i]);
    }
    cout << fixed;
    cout.precision(3);
    cout << answer << '\n';
}
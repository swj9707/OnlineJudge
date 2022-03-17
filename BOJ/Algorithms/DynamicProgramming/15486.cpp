#include <iostream>
#include <algorithm>
#define ll long long
#define MAX 1500001
using namespace std;

ll DP[MAX];
int T[MAX];
int P[MAX];
int N;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> T[i] >> P[i];
    }
    for(int i = N; i >= 1; i--){
        if(i + T[i] > N+1) DP[i] = DP[i+1];
        else DP[i] = max(DP[i+1], P[i] + DP[i + T[i]]);
    }
    cout << DP[1] << '\n';
}
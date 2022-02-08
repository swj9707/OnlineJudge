#include <iostream>
#define MAX 101
using namespace std;

long long DP[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;
    for(int i = 6; i <= 100; i++){
        DP[i] = DP[i - 5] + DP[i-1];
    }
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        cout << DP[N] << '\n';
    }
}
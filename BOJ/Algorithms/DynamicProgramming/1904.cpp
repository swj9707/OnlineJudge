#include <iostream>
#define MAX 1000001
using namespace std;

long long DP[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    DP[1] = 1;
    DP[2] = 2;
    for(int i = 3; i <= MAX; i++){
        DP[i] = DP[i - 1] % 15746 + DP[i - 2] % 15746;
    }
    int N;
    cin >> N;
    cout << DP[N] % 15746 << '\n';
}
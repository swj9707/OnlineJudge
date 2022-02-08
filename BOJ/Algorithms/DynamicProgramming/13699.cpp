#include <iostream>
#define MAX 36
using namespace std;

long long DP[MAX];

void init(){
    DP[0] = 1;
    DP[1] = 1;
    for(int i = 2; i < MAX; i++){
        long long sum = 0;
        for(int j = 0; j < i; j++){
            sum += DP[j] * DP[i - j - 1];
        }
        DP[i] = sum;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int N;
    cin >> N;
    cout << DP[N] << '\n';
}
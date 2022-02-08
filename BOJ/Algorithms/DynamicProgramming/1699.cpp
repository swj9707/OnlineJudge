#include <iostream>
#define MAX 100001
using namespace std;

int DP[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= MAX; i++){
        DP[i] = i;
        for(int j = 1; j * j <= i; j++){
            if(DP[i] > DP[i - j*j] + 1) DP[i] = DP[i - j*j] + 1; 
        }
    }
    int N;
    cin >> N;
    cout << DP[N] << '\n';
}
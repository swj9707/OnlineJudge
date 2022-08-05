#include <iostream>

using namespace std;

int DP[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        DP[i] = i;
    }

    for(int i = 2; i <= N; i++){
        if( i % 2 == 0){
            DP[i] = min(DP[i], DP[i / 2]);
        }
        if( i % 3 == 0){
            DP[i] = min(DP[i], DP[i / 3]);
        }
        DP[i] = min(DP[i], DP[i - 1]) + 1;
    }

    cout << DP[N] - 1 << '\n';

    while(N != 0){
        cout << N << " ";
		if (DP[N] == DP[N - 1] + 1) {
			N = N - 1;
		}
		else if (N%2 == 0 && DP[N] == DP[N / 2] + 1) {
			N = N / 2;
		}
		else if (N%3 == 0 && DP[N] == DP[N / 3] + 1) {
			N = N / 3;
		}
    }

}
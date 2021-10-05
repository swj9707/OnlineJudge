#include <iostream>
#define MOD 10007
using namespace std;

int main() {
	int DP[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int N;
	int sum = 0;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		for (int j = 8; j >= 0; j--) {
			DP[j] = DP[j + 1] + DP[j];
		}		
		for (int j = 8; j >= 0; j--) {
			DP[j] %= MOD;
		}
	}
	for (int i = 0; i < 10; i++) sum += DP[i] % MOD;
	cout << sum % MOD << '\n';
	return 0;
}
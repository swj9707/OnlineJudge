#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int T;
	cin >> T;
	int DP[31][31] = { 0, };
	for (int i = 1; i <= 30; i++) {
		DP[1][i] = i;
	}
	for (int i = 2; i <= 30; i++) {
		for (int j = i; j <= 30; j++) {
			for (int k = j - 1; k >= 1; k--) {
				DP[i][j] += DP[i - 1][k];
			}
		}
	}
	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		cout << DP[N][M] << '\n';

	}
}

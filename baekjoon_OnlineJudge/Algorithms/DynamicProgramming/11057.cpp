#include <iostream>
#include <vector>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init(); 
	int N;
	cin >> N;
	vector<int> DP(10, 1);
	int answer = 0;
	if (N == 1) {
		cout << "10" << '\n';
		return 0;
	}
	else {
		for (int i = 1; i < N; i++) {
			for (int j = 8; j >= 0; j++) {
				DP[i] = DP[i - 1] + DP[i];
			}
		}
		for (int i = 0; i < DP.size(); i++) {
			answer += DP[i] %10007;
		}
	}
	cout << answer % 10007 << '\n';
	return 0;
}

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int N;
	cin >> N;
	vector<int> data(N);
	vector<int> DP(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
		DP[i] = data[i];
	}
	int answer = DP[0];
	for (int i = 1; i < N; i++) {
		DP[i] = max(DP[i], DP[i - 1] + data[i]);
		if (answer < DP[i]) answer = DP[i];
	}
	cout << answer << '\n';
}
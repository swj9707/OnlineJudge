#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	int N;
	cin >> N;
	vector<int> data(N);
	int dp[MAX] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}
	int answer = dp[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i], dp[i - 1] + data[i]);
		if (answer < dp[i]) answer = dp[i];
	}
	cout << answer << '\n';
}
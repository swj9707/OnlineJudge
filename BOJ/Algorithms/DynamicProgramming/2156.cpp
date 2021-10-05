#include <iostream>
#define MAX 10001
using namespace std;

int data[MAX];
int dp[MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> data[i];
	}
	dp[0] = data[0] = 0;
	dp[1] = data[1];
	dp[2] = data[1] + data[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + data[i - 1] + data[i], max(dp[i - 2] + data[i], dp[i - 1]));
	}
	cout << dp[n] << '\n';
}
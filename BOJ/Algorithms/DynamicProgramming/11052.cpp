#include <iostream>
#define MAX 1001

using namespace std;

int card[MAX];
int dp[MAX];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}
	dp[1] = card[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[N] << '\n';
}
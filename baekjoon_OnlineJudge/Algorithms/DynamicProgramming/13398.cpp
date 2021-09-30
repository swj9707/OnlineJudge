#include <iostream>
#include <vector>
#include <algorithm>

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
	vector<int> dp(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
		dp[i] = data[i];
	}
	int min_index = min_element(data.begin(), data.end()) - data.begin();
	int answer1 = dp[0];
	for (int i = 1; i < data.size(); i++) {
		dp[i] = max(dp[i], dp[i - 1] + data[i]);
		if (answer1 < dp[i]) answer1 = dp[i];
	}
	data.erase(data.begin() + min_index);
	vector<int> dp2(N, 0);
	for (int i = 0; i < data.size(); i++) {
		dp2[i] = data[i];
	}
	int answer2 = dp2[0];
	for (int i = 1; i < data.size(); i++) {
		dp2[i] = max(dp2[i], dp2[i - 1] + data[i]);
		if (answer2 < dp2[i]) answer2 = dp2[i];
	}
	int answer = max(answer1, answer2);
	cout << answer << '\n';
}
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
	vector<pair<int, int>> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i].second >> data[i].first;
	}
	sort(data.begin(), data.end());
	int time = 0;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (time <= data[i].second) {
			time = data[i].first;
			answer += 1;
		}
	}
	cout << answer << '\n';
}
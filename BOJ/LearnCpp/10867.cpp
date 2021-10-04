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
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		answer.push_back(data);
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}
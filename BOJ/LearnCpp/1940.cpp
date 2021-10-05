#include <iostream>
#include <vector>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int N, M, answer = 0;
	cin >> N;
	cin >> M;
	vector<int> met;
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		met.push_back(data);
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (met[i] + met[j] == M) {
				answer += 1;
			}
		}
	}
	cout << answer;
}
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
	vector<int> dpLeft(N, 0);
	vector<int> dpRight(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
		dpLeft[i] = data[i];
		dpRight[i] = data[i];
	}
	int answer = dpLeft[0];
	for (int i = 1; i < N; i++) {
		dpLeft[i] = max(dpLeft[i], dpLeft[i - 1] + data[i]);
		answer = max(answer, dpLeft[i]);
	}
	for (int i = N - 2; i >= 0; i--) {
		dpRight[i] = max(dpRight[i], dpRight[i + 1] + data[i]);
	}
	for (int i = 1; i < N -1 ; i++) answer = max(answer, dpLeft[i - 1] + dpRight[i + 1]);
	cout << answer << '\n';

}
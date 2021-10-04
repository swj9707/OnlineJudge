#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int answer = 0;
	cin >> N;
	vector<int> A;
	vector<int> B;

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		A.push_back(data);
	}
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		B.push_back(data);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[i];
	}
	cout << answer << '\n';
}
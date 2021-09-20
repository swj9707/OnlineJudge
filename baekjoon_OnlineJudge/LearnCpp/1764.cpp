#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> A;
	vector<string> B;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (binary_search(A.begin(), A.end(), str)) {
			B.push_back(str);
		}
	}
	sort(B.begin(), B.end());
	cout << B.size() << '\n';
	for (int i = 0; i < B.size(); i++) {
		cout << B[i] << '\n';
	}
}
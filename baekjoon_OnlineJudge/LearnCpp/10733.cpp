#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	vector<int> V;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int append;
		cin >> append;
		if (append == 0) V.pop_back();
		else V.push_back(append);
	}
	int sum = accumulate(V.begin(), V.end(), 0);
	cout << sum << '\n';
}
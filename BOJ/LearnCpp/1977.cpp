#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int M, N;
	int sum = 0;
	int min = -9999;
	vector<int> v;
	cin >> M;
	cin >> N;// M <= N
	for (int i = 1; i * i <= N; i++) {
		if (i * i >= M && i * i <= N) {
			v.push_back(i * i);
			sum += i * i;
		}
	}
	if (v.size() == 0) cout << "-1" << endl;
	else {
		cout << sum << endl;
		cout << v.front() << endl;
	}
}
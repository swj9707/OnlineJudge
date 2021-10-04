#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> vec;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		vec.push_back(data);
	}
	int count = 0;
	for (int i = vec.size() - 1; i >= 0; i--) {
		if (K / vec[i] != 0) {
			count += (K / vec[i]);
			K = K % vec[i];
		}
	}
	cout << count << '\n';
}
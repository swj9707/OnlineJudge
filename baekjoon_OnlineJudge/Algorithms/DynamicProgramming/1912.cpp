#include <iostream>
#include <vector>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	int N;
	cin >> N;
	vector<int> data(N);
	for (int i = 0; i < N; i++) {
		cin >> data[i];
	}	
	for (int i = 0; i < N; i++) {
		cout << data[i] << " ";
	}
	cout << '\n';
}
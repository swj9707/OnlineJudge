#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	int Sum;
	cin >> Sum;
	int sum2 = 0;
	for (int i = 0; i < 9; i++) {
		int data;
		cin >> data;
		sum2 += data;
	}
	cout << Sum - sum2 << '\n';
}
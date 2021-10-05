#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num[5];
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
	}
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += num[i] * num[i];
	}
	cout << sum % 10 << '\n';
}

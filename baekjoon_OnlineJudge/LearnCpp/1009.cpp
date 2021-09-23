#include <iostream>
#include <cmath>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;
		int result;
		B = B % 4;
		if (B == 0) B = 4;
		if (A % 10 == 0) result = 10;
		else {
			result = pow(A, B);
			result = result % 10;
		}
		cout << result << '\n';
	}
}
#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	init();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;
		if (A < B) {
			int tmp;
			tmp = A;
			A = B;
			B = tmp;
		}
		cout << lcm(A, B) << " " << gcd(A, B) << '\n';
	}
}
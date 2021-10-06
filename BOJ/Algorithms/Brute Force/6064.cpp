#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int limit = lcm(M, N);
		int j;
		for (j = x; j <= limit; j + M) {
			int tmp = (j % N == 0) ? N : j % N;
			if (tmp == y) {
				cout << j << '\n';
				break;
			}
		}
		if (j > limit) cout << " - 1\n";
	}
}
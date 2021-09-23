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
		int tmp = A % 10;
		B = B % 4;
		do {
			tmp = (tmp * A) % 10;
		} while (B > 1);
		cout << tmp << '\n';
	}
}
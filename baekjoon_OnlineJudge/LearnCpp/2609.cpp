#include <iostream>

using namespace std;

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
	int A, B;
	cin >> A >> B;
	cout << gcd(A, B) << '\n';
	cout << lcm(A, B) << '\n';
}
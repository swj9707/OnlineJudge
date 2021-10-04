#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

long long gcd(long long a, long long b) {
	long long c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

void swap(long long *a, long long *b) {
	long long t;
	t = *a;
	*a = *b;
	*b = t;
}

int main() {
	init();
	long long N;
	cin >> N;
	for (long long i = 0; i < N; i++) {
		long long A, B;
		cin >> A >> B;
		if (A < B) swap(&A, &B);
		long long answer = lcm(A, B);
		cout << answer << '\n';
	}
}
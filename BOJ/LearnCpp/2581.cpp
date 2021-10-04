#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int N) {
	if (N == 1) return false;
	else {
		for (int i = 2; i <= sqrt(N); i++) {
			if (N % i == 0) return false;
		}
		return true;
	}
}

int main() {
	int M, N;
	cin >> M >> N;
	int min;
	int sum = 0;
	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			if (sum == 0) min = i;
			sum += i;
		}
	}
	if (sum == 0) cout << "-1" << '\n';
	else {
		cout << sum << '\n';
		cout << min << '\n';
	}
}
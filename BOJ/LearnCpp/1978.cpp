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
	int N;
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (isPrime(a)) answer += 1;
	}
	cout << answer << '\n';
}
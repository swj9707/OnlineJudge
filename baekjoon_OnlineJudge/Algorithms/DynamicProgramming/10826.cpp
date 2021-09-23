#include <iostream>

using namespace std;

int main() {
	int fibonazzi[100001] = { 0, };
	fibonazzi[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		fibonazzi[i] = fibonazzi[i - 1] + fibonazzi[i - 2];
	}
	int n;
	cin >> n;
	cout << fibonazzi[n] << '\n';
}
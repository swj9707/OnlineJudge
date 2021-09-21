#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B;
	int Max = -99999;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		cin >> A >> B;
		int numof = B - A;
		sum += numof;
		if (Max < sum) Max = sum;
	}
	cout << Max << '\n';
}

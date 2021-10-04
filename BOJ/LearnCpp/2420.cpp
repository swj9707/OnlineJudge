#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long A, B;
	cin >> A >> B;
	long long answer = A - B;
	if (answer < 0) answer = (-1) * answer;
	cout << answer << '\n';
}

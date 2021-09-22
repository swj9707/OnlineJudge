#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int data[1000];
	int num = 0;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < i && num < 1000; j++) {
			data[num++] = i;
		}
	}
	int A, B;
	cin >> A >> B;
	int answer = 0;
	for (int i = A; i <= B; i++) {
		answer += data[i-1];
	}
	cout << answer << '\n';
}

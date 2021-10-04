#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		string A;
		getline(cin, A);
		if (A == "END") break;
		for (int i = A.length() - 1; i >= 0; i--) cout << A[i];
		cout << '\n';
	}
}
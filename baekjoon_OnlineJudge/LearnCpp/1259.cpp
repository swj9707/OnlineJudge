#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string N;
	while (true) {
		cin >> N;
		if (N != "0") {
			string tmp = N;
			reverse(N.begin(), N.end());
			if (tmp == N) cout << "yes\n";
			else cout << "no\n";
		}
		else return 0;
	}
}

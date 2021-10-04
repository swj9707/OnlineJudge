#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string N;
	char data[10] = { 'a','A','e','E','i','I','o','O','u','U' };
	while (true) {
		getline(cin, N);
		int count = 0;
		if (N != "#") {
			for (int i = 0; i < N.size(); i++) {
				for (int j = 0; j < 10; j++) {
					if (N[i] == data[j]) count += 1;
				}
			}
			cout << count << '\n';
		}
		else return 0;
	}
}

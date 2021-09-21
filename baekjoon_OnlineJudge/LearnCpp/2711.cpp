#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A;
		string str;
		cin >> A >> str;
		for (int j = 0; j < str.size(); j++) {
			if (A - 1 != j) cout << str[j];
		}
		cout << '\n';
	}
}

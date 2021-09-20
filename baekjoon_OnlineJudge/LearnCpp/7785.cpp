#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int N;
	cin >> N;
	set<string> answer;
	for (int i = 0; i < N; i++) {
		string A, B;
		cin >> A >> B;
		if (B == "enter") {
			answer.insert(A);
		}
		else if (B == "leave") {
			answer.erase(A);
		}
	}
	for (auto iter = answer.rbegin(); iter != answer.rend(); iter++) {
		cout << *iter << '\n';
	}
}
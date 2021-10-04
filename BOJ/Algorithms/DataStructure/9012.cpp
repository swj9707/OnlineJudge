#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		stack<char> stk;
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') stk.push(str[j]);
			else if (str[j] == ')') {
				if (!stk.empty()) stk.pop();
			}
		}
		if (stk.empty()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
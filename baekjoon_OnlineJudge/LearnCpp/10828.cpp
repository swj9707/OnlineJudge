#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> stack;

	for (int i = 0; i < N; i++) {
		string A;
		cin >> A;
		if (A == "push") {
			int num;
			cin >> num;
			stack.push(num);
		}
		else if (A == "pop") {
			if (!stack.empty()) {
				cout << stack.top() << '\n';
				stack.pop();
			}
			else {
				cout << "-1" << '\n';
			}
		}
		else if (A == "size") {
			cout << stack.size() << endl;
		}
		else if (A == "empty") {
			if (stack.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if (A == "top") {
			if (!stack.empty()) {
				cout << stack.top() << '\n';
			}
			else {
				cout << "-1" << '\n';
			}
		}
	}
}
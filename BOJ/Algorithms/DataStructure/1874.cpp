#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> stk;
	stk.push(-99999);
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		if (stk.top() < data) stk.push(data);
		else stk.pop();
	}

}


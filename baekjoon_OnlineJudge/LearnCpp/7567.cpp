#include <iostream>
#include <string>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	string str;
	int sum = 10;
	cin >> str;
	for (int i; i < str.size(); i++) {
        if ((str[i] == ')' && str[i + 1] == '(') || (str[i] == '(' && str[i + 1] == ')') && i + 1 < str.size()){
            sum += 10;
        }
        else if ((str[i] == ')' && str[i + 1] == ')') || (str[i] == '(' && str[i + 1] == '(') && i + 1 < str.size()){
            sum += 5;
        }
	}
	cout << sum << '\n';
}
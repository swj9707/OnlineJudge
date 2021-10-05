#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int N;
	cin >> N;
	N % 2 == 1 ? cout << "SK\n" : cout << "CY\n";
}
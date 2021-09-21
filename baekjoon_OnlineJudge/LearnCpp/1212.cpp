#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string N;
	cin >> N;
	if (N == "0") cout << "0\n";
	else {
		for (int i = 0; i < N.length(); i++) {
			switch (N[i] - '0')
			{
			case 0:
				cout << "000";
				break;
			case 1:
				if (!i)
					cout << "1";
				else
					cout << "001";
				break;
			case 2:
				if (!i)
					cout << "10";
				else
					cout << "010";
				break;
			case 3:
				if (!i)
					cout << "11";
				else
					cout << "011";
				break;
			case 4:
				cout << "100";
				break;
			case 5:
				cout << "101";
				break;
			case 6:
				cout << "110";
				break;
			case 7:
				cout << "111";
				break;
			}
		}
		cout << "\n";
	}
}
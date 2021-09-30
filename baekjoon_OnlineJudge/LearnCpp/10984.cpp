#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int N;
		cin >> N;
		int c = 0;
		double g = 0;
		for (int j = 0; j < N; j++) {
			int _c;
			double _g;
			cin >> _c >> _g;
			c += _c;
			g += _g * _c;
		}
		cout << c << " " << g / c << '\n';
	}
}
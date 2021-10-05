#include <iostream>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int AScore = 0;
		int BScore = 0;
		for (int j = 0; j < 9; j++) {
			int A, B;
			cin >> A >> B;
			AScore += A;
			BScore += B;
		}
		if (AScore > BScore) cout << "Yonsei" << '\n';
		else if (AScore < BScore) cout << "Korea" << '\n';
		else cout << "Draw" << '\n';
	}
}
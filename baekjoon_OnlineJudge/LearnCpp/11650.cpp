#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<vector<int>> Vec(N, vector<int>(2, 0));
	for (int i = 0; i < N; i++) {
		cin >> Vec[i][0] >> Vec[i][1];
	}
	sort(Vec.begin(), Vec.end());
	for (int i = 0; i < N; i++) {
		cout << Vec[i][0] << " " << Vec[i][1] << '\n';
	}
}
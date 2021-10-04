#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector <pair<pair<int, int>, pair<int, string>>> V(N);

	for (int i = 0; i < N; i++) {
		cin >> V[i].second.second >> V[i].second.first >> V[i].first.second >> V[i].first.first;
	}
	sort(V.begin(), V.end());
	cout << V[N - 1].second.second << endl;
	cout << V[0].second.second << endl;
}
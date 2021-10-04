#include <iostream>
#include <algorithm>

using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int M, N;
	cin >> N >> M;
	int max_Set = 9999;
	int max_Indiv = 9999;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		if (A < max_Set) max_Set = A;
		if (B < max_Indiv) max_Indiv = B;
	}
	cout << min((N / 6 + 1) * max_Set, min(N / 6 * max_Set + N % 6 * max_Indiv, N * max_Indiv)) << '\n';
}
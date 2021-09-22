#include <iostream>
#include <algorithm>
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

void Horizontal(char ** board, int N) {
	for (int i = 0; i < N; i++) {
		int count = 1;
		for (int j = 0; j < N; j++) {
			if (board[i][j] == arr[i][j + 1]) count++;
			else {
				if()
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	char board[51][51];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(board[i][j], board[i][j + 1]);

		}
	}

}
#include <iostream>
#include <queue>
#define MAX 100000;
using namespace std;
int N, K;
int dx[3];
int MATRIX[]
queue<int> q;
int BFS() {
	int result = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		dx[0] = x - 1;
		dx[1] = x + 1;
		dx[2] = 2 * x;
		for (int i = 0; i < 3; i++) {
			if (dx[i] >= 0) {

			}
		}
		
	}
}

int main() {
	cin >> N >> K;
}
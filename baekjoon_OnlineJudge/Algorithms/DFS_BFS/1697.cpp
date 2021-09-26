#include <iostream>
#include <queue>

using namespace std;
int N, K;
int dx[3];
queue<int> q;
void BFS() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		dx[0] = x - 1;
		dx[1] = x + 1;
		dx[2] = 2 * x;
		
	}
}

int main() {
	cin >> N >> K;
}
#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;
int N, K;
bool visit[MAX];

int BFS(int n) {
	queue< pair<int, int> > q;
	q.push({ n, 0 });
	visit[n] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();
		if (x == K) return time;
		if (x + 1 < MAX && !visit[x + 1]) {
			q.push({ x + 1, time + 1 });
			visit[x + 1] = true;
		}
		if (x - 1 >= 0 && !visit[x - 1]) {
			q.push({ x - 1, time + 1 });
			visit[x - 1] = true;
		}
		if (x * 2 < MAX && !visit[x * 2]) {
			q.push({ x * 2, time + 1 });
			visit[x * 2] = true;
		}
		
	}
}

int main() {
	cin >> N >> K;
	cout << BFS(N) << '\n';
}
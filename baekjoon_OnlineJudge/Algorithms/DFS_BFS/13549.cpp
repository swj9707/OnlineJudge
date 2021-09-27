#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;
int N, K;
bool visit[MAX];

int BFS(int n) {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
	q.push({ n, 0 });
	visit[n] = true;
	while (!q.empty()) {
		int x = q.top().first;
		int time = q.top().second;
		q.pop();
		if (x == K) return time;		
		if (x * 2 < MAX && !visit[x * 2]) {
			q.push({ x * 2, time});
			visit[x * 2] = true;
		}
		if (x + 1 < MAX && !visit[x + 1]) {
			q.push({ x + 1, time + 1 });
			visit[x + 1] = true;
		}
		if (x - 1 >= 0 && !visit[x - 1]) {
			q.push({ x - 1, time + 1 });
			visit[x - 1] = true;
		}
	}
}

int main() {
	cin >> N >> K;
	cout << BFS(N) << '\n';
}
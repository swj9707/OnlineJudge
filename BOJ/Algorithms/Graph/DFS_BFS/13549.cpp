#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;
int N, K;
bool visit[MAX];

int BFS(int n) {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
	q.push({ 0, n });
	visit[n] = true;
	while (!q.empty()) {
		int time = q.top().first;
		int x = q.top().second;
		q.pop();
		if (x == K) return time;		
		if (x * 2 < MAX && !visit[x * 2]) {
			q.push({ time, x * 2});
			visit[x * 2] = true;
		}
		if (x + 1 < MAX && !visit[x + 1]) {
			q.push({ time + 1, x + 1 });
			visit[x + 1] = true;
		}
		if (x - 1 >= 0 && !visit[x - 1]) {
			q.push({ time + 1, x - 1 });
			visit[x - 1] = true;
		}
	}
}

int main() {
	cin >> N >> K;
	cout << BFS(N) << '\n';
}
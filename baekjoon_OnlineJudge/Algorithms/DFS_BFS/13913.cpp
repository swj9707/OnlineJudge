#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001

using namespace std;
int N, K;
int parent[MAX];
bool visit[MAX];
vector <int> result;

int BFS(int n) {
	queue< pair<int, int> > q;
	q.push({ n, 0 });
	visit[n] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();

		if (x == K) {
			int idx = x;
			while (idx != N) {
				result.push_back(idx);
				idx = parent[idx];
			}
			result.push_back(N);
			return time;
		}
		if (x + 1 < MAX && !visit[x + 1]) {
			q.push({ x + 1, time + 1 });
			visit[x + 1] = true;
			parent[x + 1] = x;
		}
		if (x - 1 >= 0 && !visit[x - 1]) {
			q.push({ x - 1, time + 1 });
			visit[x - 1] = true;
			parent[x - 1] = x;
		}
		if (x * 2 < MAX && !visit[x * 2]) {
			q.push({ x * 2, time + 1 });
			visit[x * 2] = true;
			parent[x * 2] = x;
		}
	}
}

int main() {
	cin >> N >> K;
	cout << BFS(N) << '\n';
	for (int i = result.size()-1; i >= 0; i--) {
		cout << result[i] << " ";
	}
	cout << '\n';
}
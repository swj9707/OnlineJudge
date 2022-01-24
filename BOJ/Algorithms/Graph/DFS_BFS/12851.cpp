#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;
int N, K;
bool visit[MAX];

void BFS(int n) {
	queue< pair<int, int> > q;
	q.push({ n, 0 });
	visit[n] = true;
    int count = 0;
    int minsec = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();
        visit[x] = true;
        if(minsec && minsec == time && x == K) count++;
		if (x == K && !minsec){
            minsec = time;
            count++;
        }
		if (x + 1 < MAX && !visit[x + 1]) {
			q.push({ x + 1, time + 1 });
		}
		if (x - 1 >= 0 && !visit[x - 1]) {
			q.push({ x - 1, time + 1 });
		}
		if (x * 2 < MAX && !visit[x * 2]) {
			q.push({ x * 2, time + 1 });
		}		
	}
    cout << minsec << '\n';
    cout << count << '\n';
}

int main() {
	cin >> N >> K;
	BFS(N);
}
#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int S;
bool visited[MAX][MAX]; //display, clipboard

typedef struct node {
	int display, clipboard, time;
} node;


int BFS(int S) {
	queue < node> Q;
	Q.push({ 1, 0, 0 });
	visited[1][0] = true;
	while (!Q.empty()) {
		int display = Q.front().display;
		int clipboard = Q.front().clipboard;
		int time = Q.front().time;
		Q.pop();
		if (display == S) return time;
		if (0 < display && display < MAX) {
			if (!visited[display][display]) {
				visited[display][display] = true;
				Q.push({ display, display, time + 1 });
			}
		}
		if (clipboard > 0 && display + clipboard < MAX) {
			if (!visited[display + clipboard][clipboard]) {
				visited[display + clipboard][clipboard] = true;
				Q.push({ display + clipboard, clipboard, time + 1 });
			}
		}
		if (!visited[display - 1][clipboard]) {
			visited[display-1][clipboard] = true;
			Q.push({ display-1, clipboard, time + 1 });
		}
	}

}

int main() {
	cin >> S;
	cout << BFS(S) << '\n';
}

#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int matrix[MAX][MAX];
bool visit[MAX][MAX];

int dx = { 1, -1, 0, 0 };
int dy = { 0, 0, 1, -1 };

int M, N;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) cin >> matrix[i][j];
	}

}

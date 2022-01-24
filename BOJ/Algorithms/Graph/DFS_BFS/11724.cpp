#include <iostream>
#define MAX 1001
using namespace std;

int matrix[MAX][MAX];
int N, M;
bool visitList[MAX];

void dfs(int a) {
	visitList[a] = 1;
	for (int i = 1; i <= N; i++) {
		if (!visitList[i] && matrix[a][i]) {
			dfs(i);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int U, V;
		cin >> U >> V;
		matrix[U][V] = 1;
		matrix[V][U] = 1;
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!visitList[i]) {
			dfs(i);
			count += 1;
		}
	}
	cout << count << '\n';
}

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#defin MAX 25;
using namespace std;

int map[MAX][MAX];
bool visited[MAX][MAX];

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int N;
	cin >> N;
	int** map = (int**)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) map[i] = (int*)malloc(sizeof(int) * N);


}

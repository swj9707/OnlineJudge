#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define MAX 10001
using namespace std;

int N, M;
vector <int> vec[MAX];
vector <int> check;
bool visit[MAX];
int cnt;

void DFS(int X) {
	visit[X] = true;

	for (int i = 0; i < vec[X].size(); i++) {
		int Next = vec[X][i];

		if (!visit[Next]) {
			cnt++;
			DFS(Next);
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int Start_point, End_point;
		cin >> Start_point >> End_point;
		vec[End_point].push_back(Start_point);
	}
	
	int node_count = 0;

	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		cnt = 0;
		
		DFS(i);
		if (node_count == cnt)
			check.push_back(i);

		else if (node_count < cnt) {
			node_count = cnt;
			check.clear();
			check.push_back(i);
		}
	}
	
	sort(check.begin(), check.end());
	for (int i = 0; i < check.size(); i++) cout << check[i] << " ";
	
	return 0;
}
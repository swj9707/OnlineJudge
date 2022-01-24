#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int u, v;
queue<int> q;
vector<int> node[50001];
bool check[50001];
int parents[50001];
int depths[50001];

int LCA(int u, int v)
{
	// v가 u보다 더 깊은 노드로 세팅
	if (depths[u] > depths[v]) swap(u, v);
	
	// 두 노드의 깊이가 같아질때까지 v노드는 위로 거슬러 올라감
	while (depths[u] != depths[v]) v = parents[v];
	
	// 두 노드가 같아질때 까지 위로 거슬러 올라감
	while (u != v)
	{
		u = parents[u];
		v = parents[v];
	}
	return u; // LCA 리턴
}

void DFS(int current, int depth, int parent){
    depths[current] = depth;
    parents[current] = parent;
    for(int next : node[current]){
        if(next != parent){
            DFS(next, depth+1, current);
        }
    }
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	DFS(1, 1, 0);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}

}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int u, v;
queue<int> q;
vector<int> node[100001];
bool check[100001];
int parent[100001][20];
int depth[100001];

int LCA(int u, int v)
{
	if (depth[u] > depth[v]) swap(u, v);
	while (depth[u] != depth[v])
	{
		int dist = depth[v] - depth[u];
		for (int i = 0; i < 20; i++)
		{
			if (dist <= (2 << i))
			{
				v = parent[v][i];
				break;
			}
		}
	}

	while (u != v)
	{
		for (int i = 0; i < 20; i++)
		{
			if (parent[u][i + 1] == parent[v][i + 1])
			{
				u = parent[u][i];
				v = parent[v][i];
				break;
			}
		}
    }
	return u; 
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	check[1] = true;
	q.push(1); 
	while (!q.empty())
	{
		int x = q.front(); 
		q.pop();

		for (int i = 0; i < node[x].size(); i++)
		{
			int child = node[x][i];

			if (!check[child]) 
			{
				depth[child] = depth[x] + 1; 
				check[child] = true;
				parent[child][0] = x;
				for (int j = 0; j < 20; j++) 
				{
					parent[child][j + 1] = parent[parent[child][j]][j];
					if (parent[child][j + 1] == 0) break;
				}
				q.push(child);
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}
}
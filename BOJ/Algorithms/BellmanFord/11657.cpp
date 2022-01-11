#include <iostream>
#include <vector>
#define MAX 501
#define INF 987654321
using namespace std;
int N, M;
vector<pair<int, int>> vec[MAX];
long long DISTANCE[MAX];

bool bellman_ford(int start)
{
    DISTANCE[start] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < vec[j].size(); k++)
            {
                int next = vec[j][k].first;
                int cost = vec[j][k].second;
                if (DISTANCE[j] != INF && DISTANCE[next] > DISTANCE[j] + cost)
                {
                    DISTANCE[next] = DISTANCE[j] + cost;
                    if (i == N)
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        DISTANCE[i] = INF;
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        vec[A].push_back({B, C});
    }
    bool negative_cycle = bellman_ford(1);
    if (negative_cycle)
        cout << "-1\n";
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (DISTANCE[i] == INF)
                cout << "-1\n";
            else
                cout << DISTANCE[i] << '\n';
        }
    }
}
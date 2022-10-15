#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> houseList;
vector<pair<int, int>> chickenList;
bool VISIT[14];
int MATRIX[14];
int answer = 98765432;

int returnChickenLength(pair<int, int> house, pair<int, int> chicken)
{
    return abs(house.first - chicken.first) + abs(house.second - chicken.second);
}

void DFS(int count, int x, int M)
{
    if (count == M)
    {
        int result = 0;
        for (int i = 0; i < houseList.size(); i++)
        {
            int minValue = 98765432;
            for (int j = 0; j < M; j++)
            {
                minValue = min(minValue, returnChickenLength(houseList[i], chickenList[MATRIX[j]]));
            }
            result += minValue;
        }
        answer = min(answer, result);
    }

    for (int i = x; i < chickenList.size(); i++)
    {
        if (!VISIT[i])
        {
            VISIT[i] = true;
            MATRIX[count] = i;
            DFS(count + 1, i, M);
            VISIT[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
            {
                houseList.push_back({i, j});
            }
            else if (tmp == 2)
            {
                chickenList.push_back({i, j});
            }
        }
    }
    DFS(0, 0, M);
    cout << answer << '\n';
}
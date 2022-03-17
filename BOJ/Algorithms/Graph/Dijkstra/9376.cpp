#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#define MAX 101
#define INF 98765
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

char MATRIX[MAX][MAX];
vector<pair<int, int>> prisoner;


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
    while(T--){
        int h, w; cin >> h >> w;
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> MATRIX[i][j];
                if(MATRIX[i][j] == '$') prisoner.push_back({i, j});
            }
        }
    }

	for (int t = 0; t < T; t++)
	{
		int H, W;
		cin >> H >> W;

		string room[MAX];
		// 위 아래 . 으로 채우기
		for (int i = 0; i <= W + 1; i++)
		{
			room[0].push_back('.');
			room[H + 1].push_back('.');
		}

		vector<pair<int, int>> prisoner;
		prisoner.push_back({ 0, 0 }); // 상근이

		for (int i = 1; i <= H; i++)
		{
			cin >> room[i];

			// 마찬가지로 양 끝 .으로 채우기
			room[i] = '.' + room[i];
			for (int j = 1; j <= W; j++)
			{
				if (room[i][j] == '$')
					prisoner.push_back({ i, j });
			}
			room[i].push_back('.');
		}

		int distance[3][MAX][MAX];
		for (int i = 0; i < 3; i++)
		{
			// {거리, {죄수 좌표}}
			priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
			for (int j = 0; j <= H + 1; j++)
			{
				for (int k = 0; k <= W + 1; k++)
				{
					distance[i][j][k] = INF;
				}
			}

			pq.push({ 0,{ prisoner[i] } });
			distance[i][prisoner[i].first][prisoner[i].second] = 0;

			bool visited[MAX][MAX] = { false, };
			while (!pq.empty())
			{
				int y = pq.top().second.first;
				int x = pq.top().second.second;
				pq.pop();

				for (int j = 0; j < 4; j++)
				{
					int nextY = y + moveDir[j].y;
					int nextX = x + moveDir[j].x;

					if (0 <= nextY && nextY <= H + 1 && 0 <= nextX && nextX <= W + 1)
					{
						if (visited[nextY][nextX] || room[nextY][nextX] == '*')
						{
							continue;
						}

						int nextDistance = distance[i][y][x];
						if (room[nextY][nextX] == '#')
						{
							nextDistance++;
						}

						if (distance[i][nextY][nextX] > nextDistance)
						{
							distance[i][nextY][nextX] = nextDistance;
							visited[nextY][nextX] = true;
							pq.push({ nextDistance,{ nextY, nextX } });
						}
					}
				}
			}
		}

		long long result = INF;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (room[i][j] != '*')
				{
					long long total = 0;
					for (int k = 0; k < 3; k++)
					{
						total += distance[k][i][j];
					}

					/*
					단 한번만 문을 열면 되지만
					세번 연다고 계산이 되어 있으므로
					-2를 해준다
					*/
					total -= 2 * (room[i][j] == '#');
					result = min(result, total);
				}
			}
		}

		cout << result << "\n";
	}
	return 0;
}
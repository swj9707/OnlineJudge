#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
#define MAX 300
using namespace std;

int MATRIX[MAX][MAX];
bool Visit[MAX][MAX];
vector<int> V;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;

void BFS(int Y, int X)
{
    deque<pair<int, int>> DQ;
    DQ.push_back({Y, X});
    Visit[Y][X] = true;
    while (!DQ.empty())
    {
        int y = DQ.front().first;
        int x = DQ.front().second;
        DQ.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && !Visit[ny][nx] && MATRIX[ny][nx] != 0)
            {
                Visit[ny][nx] = true;
                DQ.push_back({ny, nx});
            }
        }
    }
}

void Melt()
{
    int tmp[MAX][MAX];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tmp[i][j] = MATRIX[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp[i][j] != 0)
            {
                int count = 0;
                for (int k = 0; k < 4; k++)
                {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    if (tmp[y][x] == 0)
                        count += 1;
                }
                if(MATRIX[i][j] - count <= 0) MATRIX[i][j] = 0;
                else MATRIX[i][j] -= count;
            }
        }
    }
}

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main()
{
    initSet();
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> MATRIX[i][j];
    }
    int Answer = 0;
    bool check = false; 
    while (true)
    {
        memset(Visit, false, sizeof(Visit));
        int SearchCount = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!Visit[i][j] && MATRIX[i][j] != 0)
                {
                    SearchCount += 1;
                    if(SearchCount == 2){
                        check = true;
                        break;
                    }
                    BFS(i, j);
                }
            }
            if(SearchCount == 2) break;
        }
        if(check) break;
        if(SearchCount == 0){
            Answer = 0;
            break;
        }
        Melt();
        Answer++;
    }
    cout << Answer << '\n';
}
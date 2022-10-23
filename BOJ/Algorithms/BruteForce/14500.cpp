#include <bits/stdc++.h>

using namespace std;

int N, M;
int MATRIX[501][501];
bool VISIT[501][501];
int answer = -1;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int count, int sum, int X, int Y)
{
    if (count == 3)
    {
        answer = max(sum, answer);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = X + dx[i];
        int ny = Y + dy[i];
        if (nx > 0 && nx <= N && ny > 0 && ny <= M && !VISIT[nx][ny])
        {
            VISIT[nx][ny] = true;
            DFS(count + 1, sum + MATRIX[nx][ny], nx, ny);
            VISIT[nx][ny] = false;
        }
    }
}

void findfuck(int x, int y)
{
    if (x + 1 <= N && y + 2 <= M)
        answer = max(answer, MATRIX[x][y] + MATRIX[x][y + 1] + MATRIX[x][y + 2] + MATRIX[x + 1][y + 1]);
    // ㅏ
    if (x + 2 <= N && y + 1 <= M)
        answer = max(answer, MATRIX[x][y] + MATRIX[x + 1][y] + MATRIX[x + 1][y + 1] + MATRIX[x + 2][y]);
    // ㅗ
    if (x - 1 > 0 && y + 2 <= M)
        answer = max(answer, MATRIX[x][y] + MATRIX[x][y + 1] + MATRIX[x][y + 2] + MATRIX[x - 1][y + 1]);
    // ㅓ
    if (x + 2 <= N && y - 1 > 0)
        answer = max(answer, MATRIX[x][y] + MATRIX[x + 1][y] + MATRIX[x + 1][y - 1] + MATRIX[x + 2][y]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> MATRIX[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            findfuck(i, j);
            VISIT[i][j] = true;
            DFS(0, MATRIX[i][j], i, j);
            VISIT[i][j] = false;
        }
    }

    cout << answer << '\n';
}
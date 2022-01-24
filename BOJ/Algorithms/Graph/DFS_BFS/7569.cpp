#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

typedef struct
{
    int x, y, z;
    int cnt;
} types;

int M, N, H;
int MATRIX[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int moveX[6] = {1, -1, 0, 0, 0, 0};
int moveY[6] = {0, 0, 1, -1, 0, 0};
int moveZ[6] = {0, 0, 0, 0, 1, -1};
queue<types> bfs;
void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int BFS()
{
    int cnt = 0;
    while (!bfs.empty())
    {
        auto a = bfs.front();
        bfs.pop();
        cnt = max(cnt, a.cnt);
        for (int i = 0; i < 6; i++)
        {
            int nx = a.x + moveX[i];
            int ny = a.y + moveY[i];
            int nz = a.z + moveZ[i];

            if (nx >= 0 && ny >= 0 && nz >= 0 && nx < N && ny < M && nz < H && !visited[nx][ny][nz])
            {
                bfs.push({nx, ny, nz, a.cnt + 1});
                visited[nx][ny][nz] = true;
            }
        }
    }
    return cnt;
}

int main(void)
{
    init();
    int cnt = 0;
    cin >> M >> N >> H;
    for (int k = 0; k < H; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                cin >> MATRIX[i][j][k];
                if (MATRIX[i][j][k] == 1)
                {
                    bfs.push({i, j, k, 0});
                    visited[i][j][k] = true;
                }
                else if (MATRIX[i][j][k] == -1)
                    visited[i][j][k] = true;
            }
    
    if (bfs.empty())
    {
        cout << "-1\n";
        return 0;
    }

    cnt = BFS();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < H; k++)
                if (!visited[i][j][k])
                {            
                    cout << "-1\n";
                    return 0;
                }

    cout << cnt << '\n';
    return 0;
}
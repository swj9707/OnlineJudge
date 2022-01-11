#include <iostream>
#define MAX 101
#define INF 999999999
using namespace std;
int N, M;
int MATRIX[MAX][MAX];

void floyd_warshall()
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (MATRIX[j][i] != INF && MATRIX[i][k] != INF)
                {
                    if (MATRIX[i][j] > MATRIX[i][k] + MATRIX[k][j])
                        MATRIX[i][j] = MATRIX[i][k] + MATRIX[k][j];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            MATRIX[i][j] = INF;
    }
    for (int i = 0; i < M; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        if (MATRIX[A][B] > C) MATRIX[A][B] = C;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (i == j)
                cout << 0 << " ";
            else
                cout << MATRIX[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
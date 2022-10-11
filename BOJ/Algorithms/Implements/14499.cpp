#include <bits/stdc++.h>
#define MAX 21

using namespace std;

int MATRIX[MAX][MAX];
int movePointList[1000];
vector<int> dice_index(7);
// 1 위 2 북 3 동 4 서 5 남 6 아래

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

void dice_ChgIndex(int movepoint)
{
    if (movepoint == 1)
    {
        dice_index = {0, dice_index[4], dice_index[2], dice_index[1], dice_index[6], dice_index[5], dice_index[3]};
    }
    else if (movepoint == 2)
    {
        dice_index = {0, dice_index[3], dice_index[2], dice_index[6], dice_index[1], dice_index[5], dice_index[4]};
    }
    else if (movepoint == 3)
    {
        dice_index = {0, dice_index[5], dice_index[1], dice_index[3], dice_index[4], dice_index[6], dice_index[2]};
    }
    else if (movepoint == 4)
    {
        dice_index = {0, dice_index[2], dice_index[6], dice_index[3], dice_index[4], dice_index[1], dice_index[5]};
    }
}

int main()
{
    int N, M, initx, inity, K;
    //이동 방향 : 동 1 서 2 북 3 남 4
    cin >> N >> M >> inity >> initx >> K;
    //가로 세로 크기, 주사위를 놓은 곳, 명령의 갯수
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cin >> MATRIX[i][j];
    }
    for (int i = 0; i < K; i++)
        cin >> movePointList[i];
    for (int i = 0; i < K; i++)
    {
        int ny = dy[movePointList[i]] + inity;
        int nx = dx[movePointList[i]] + initx;
        if (ny >= N || ny < 0 || nx >= M || nx < 0)
        {
            continue;
        }
        inity = ny;
        initx = nx;

        dice_ChgIndex(movePointList[i]);
        cout << dice_index[1] << '\n';
        if (MATRIX[inity][initx] == 0)
        {
            MATRIX[inity][initx] = dice_index[6];
        }
        else
        {
            dice_index[6] = MATRIX[inity][initx];
            MATRIX[inity][initx] = 0;
        }
    }
}
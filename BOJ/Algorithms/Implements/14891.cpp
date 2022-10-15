#include <bits/stdc++.h>

using namespace std;

deque<int> gear[5];

void rotateClockwise(int index)
{
    int tmp = gear[index].back();
    gear[index].pop_back();
    gear[index].push_front(tmp);
}

void rotateCounterClockwise(int index)
{
    int tmp = gear[index].front();
    gear[index].pop_front();
    gear[index].push_back(tmp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int left = 0, right = 0;
    int answer = 0;
    for (int i = 1; i <= 4; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++)
        {
            gear[i].push_back(tmp[j] - '0');
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int index, direction;
        cin >> index >> direction;
        bool diff[5];
        int directionArray[5];

        fill_n(diff, 5, false);
        fill_n(directionArray, 5, 0);

        diff[index] = true;
        directionArray[index] = direction;

        for (int i = index; i < 4; i++)
        {
            if (gear[i].at(2) != gear[i + 1].at(6))
            {
                diff[i + 1] = true;
                directionArray[i + 1] = directionArray[i] * (-1);
            }
            else
            {
                break;
            }
        }
        for (int i = index; i > 1; i--)
        {
            if (gear[i].at(6) != gear[i - 1].at(2))
            {
                diff[i - 1] = true;
                directionArray[i - 1] = directionArray[i] * (-1);
            }
            else
            {
                break;
            }
        }

        for (int i = 1; i <= 4; i++)
        {
            if (diff[i])
            {
                if (directionArray[i] == 1)
                {
                    rotateClockwise(i);
                }
                else if (directionArray[i] == -1)
                {
                    rotateCounterClockwise(i);
                }
            }
        }
    }
    int score = 1;
    for (int i = 1; i <= 4; i++)
    {
        if (gear[i].front() == 1)
        {
            answer += score;
        }
        score *= 2;
    }
    cout << answer << '\n';
}
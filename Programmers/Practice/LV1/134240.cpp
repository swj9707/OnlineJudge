#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";

    for (int i = 1; i < food.size(); i++)
    {
        int count = 0;
        if (food[i] % 2 == 0)
        {
            count = food[i] / 2;
            for (int j = 0; j < count; j++)
            {
                answer += food[i] + '0';
            }
        }
        else
        {
            if (food[i] == 1)
            {
                continue;
            }
            else
            {
                count = food[i] / 2;
                for (int j = 0; j < count; j++)
                {
                    answer += food[i] + '0';
                }
            }
        }
    }
    string tmp = answer;
    reverse(tmp.begin(), tmp.end());
    answer += '0';
    for (int i = 0; i < tmp.size(); i++)
    {
        answer += tmp[i];
    }
    return answer;
}
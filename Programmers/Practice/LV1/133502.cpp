#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;

    stack<int> stk;

    for (int i = 0; i < ingredient.size(); i++)
    {
        stk.push(ingredient[i]);
        if (stk.size() >= 4)
        {
            vector<int> isHbg;
            for (int i = 0; i < 4; i++)
            {
                isHbg.push_back(stk.top());
                stk.pop();
            }

            if (isHbg[0] == 1 && isHbg[1] == 2 && isHbg[2] == 3 && isHbg[3] == 1)
            {
                answer++;
            }
            else
            {
                for (int i = 3; i >= 0; i--)
                {
                    stk.push(isHbg[i]);
                }
            }
        }
    }

    return answer;
}
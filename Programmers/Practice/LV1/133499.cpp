#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    for (auto str : babbling)
    {
        string tmp = "";
        string prev = "";
        for (auto chr : str)
        {
            tmp += chr;
            if (tmp != prev && (tmp == "aya" || tmp == "ye" || tmp == "woo" || tmp == "ma"))
            {
                prev = tmp;
                tmp = "";
            }
        }
        if (tmp.length() == 0)
        {
            answer++;
        }
    }

    return answer;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    int answer = 0;
    cin >> N >> M;
    deque<int> dq;
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        int left = 0, right = 0;
        for (int idx = 0; idx < dq.size(); idx++)
        {
            if (dq[idx] == num)
            {
                left = idx;
                right = dq.size() - idx;
                break;
            }
        }
        if (left <= right)
        {
            while (1)
            {
                if (dq.front() == num)
                {
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                answer++;
            }
            dq.pop_front();
        }
        else
        {
            answer++;
            while (1)
            {
                if (dq.back() == num)
                {
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                answer++;
            }
            dq.pop_back();
        }
    }
    cout << answer << '\n';
}
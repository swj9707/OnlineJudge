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
    for (int i = 0; i < N; i++)
    {
        dq.push_back(i + 1);
    }
    queue<int> orderData;
    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        orderData.push(tmp);
    }
    while (!orderData.empty())
    {
        if (dq.front() == orderData.front())
        {
            dq.pop_front();
            orderData.pop();
        }
        else
        {
            int tmp = dq.front();
            if (dq.front() > orderData.front())
            {
                dq.pop_back();
                dq.push_front(tmp);
            }
            else
            {
                dq.pop_front();
                dq.push_back(tmp);
            }
            answer++;
        }
    }
    cout << answer << '\n';
}
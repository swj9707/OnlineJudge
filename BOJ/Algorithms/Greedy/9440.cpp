#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while (true)
    {
        int zero = 0;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        vector<int> inputData(N);
        for (int i = 0; i < N; i++)
        {
            cin >> inputData[i];
            if (inputData[i] == 0)
            {
                zero++;
            }
        }
        sort(inputData.begin(), inputData.end());
        if (zero == 1)
        {
            swap(inputData[0], inputData[2]);
        }
        if (zero >= 2)
        {
            swap(inputData[0], inputData[zero]);
            swap(inputData[1], inputData[zero + 1]);
        }
        string left = "", right = "";
        for (int i = 0; i < inputData.size(); i++)
        {
            string now = to_string(inputData[i]);
            if (i % 2 == 0)
                left += now;
            else
                right += now;
        }
        cout << stoi(left) + stoi(right) << '\n';
    }
}
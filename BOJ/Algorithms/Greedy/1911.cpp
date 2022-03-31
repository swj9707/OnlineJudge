#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    int answer = 0, index = 0;
    cin >> N >> L;
    vector<pair<int, int>> data;
    for (int i = 0; i < N; i++)
    {
        int first, second;
        cin >> first >> second;
        data.push_back({first, second});
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++)
    {
        if (index >= data[i].second)
            continue;
        index = max(index, data[i].first);
        int count = (data[i].second - (index + 1)) / L + 1;
        answer += count;
        index += L * count;
    }

    cout << answer << '\n';
}
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ulim[9];
    int sl[9];
    for (int i = 0; i < 9; i++)
        cin >> ulim[i];
    for (int i = 0; i < 9; i++)
        cin >> sl[i];
    int ulimScore = 0, slScore = 0;
    bool whois = false, reverse = false;
    for (int i = 0; i < 9 && !reverse; i++)
    {
        ulimScore += ulim[i];
        if (ulimScore > slScore)
        {
            whois = true;
        }
        slScore += sl[i];
        if (ulimScore < slScore && whois)
        {
            reverse = true;
        }
    }
    cout << (reverse ? "Yes\n" : "No\n");
}
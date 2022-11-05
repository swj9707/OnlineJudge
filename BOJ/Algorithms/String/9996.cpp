#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string pattern;
    cin >> pattern;
    int index = pattern.find("*");
    string leftSide = pattern.substr(0, index);
    string rightSide = pattern.substr(index + 1);
    while (N--)
    {
        string cmp;
        cin >> cmp;
        if (leftSide.size() + rightSide.size() > cmp.size())
        {
            cout << "NE\n";
        }
        else if (cmp.find(leftSide) == 0)
        {
            string ex = cmp.substr(cmp.size() - (rightSide.size()));
            if (ex == rightSide)
                cout << "DA\n";
            else
                cout << "NE\n";
        }
        else
            cout << "NE\n";
    }
}
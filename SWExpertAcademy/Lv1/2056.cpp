#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string input;
        cin >> input;
        int year = stoi(input.substr(0, 4));
        int month = stoi(input.substr(4, 2));
        int date = stoi(input.substr(6, 2));
        bool Answer = false;
        if (month >= 1 && month <= 12)
        {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            {
                if (date >= 1 && date <= 31)
                    Answer = true;
            }
            else if (month == 2)
            {
                if (date >= 1 && date <= 28)
                    Answer = true;
            }
            else
            {
                if (date >= 1 && date <= 30)
                    Answer = true;
            }
        }
        if (Answer)
        {
            cout << "#" << i + 1 << " " << input.substr(0, 4) << "/" << input.substr(4, 2) << "/" << input.substr(6, 2) <<'\n';
        }
        else
            cout << "#" << i + 1 << " -1" << '\n';
    }
}

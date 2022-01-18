#include <iostream>
#include <string>
using namespace std;

int main()
{
    string inputData;
    cin >> inputData;
    string answer = "";
    int i = 0;
    int count = 0;
    while (inputData[i] != '\0')
    {
        while (inputData[i] == 'X' || inputData[i] != '.')
        {
            i++;
            count++;
            if (inputData[i] == '\0')
            {
                break;
            }
        }
        if (count % 2 == 0)
        {
            while (4 <= count)
            {
                answer += "AAAA";
                count -= 4;
            }
            while (2 <= count)
            {
                answer += "BB";
                count -= 2;
            }
        }
        if (count != 0)
        {
            cout << -1 << '\n';
            return 0;
        }
        if (inputData[i] == '.')
        {
            answer += '.';
            i++;
        }
    }
    cout << answer << '\n';
}
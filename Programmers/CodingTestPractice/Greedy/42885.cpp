#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool desc(int a, int b)
{
    return a > b;
}

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), desc);
    while (!people.empty())
    {
        if (people.size() > 1)
        {
            if (people[0] + people[people.size() - 1] <= 100)
            {
                answer++;
                people.pop_back();
                people.erase(people.begin());
            }
            else
            {
                answer++;
                people.erase(people.begin());
            }
        }
        else{
            answer++;
            people.erase(people.begin());
        }
    }
    return answer;
}

int main()
{
    vector<int> people1 = {70, 50, 80, 50};
    vector<int> people2 = {70, 80, 50};
    cout << solution(people1, 100) << '\n';
    cout << solution(people2, 100) << '\n';
}
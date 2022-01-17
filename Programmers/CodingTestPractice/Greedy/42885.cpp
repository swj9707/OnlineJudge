#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size()-1;
    while(left <= right){
        if(people[left] + people[right] < limit){
            left++;
            right--;
        }
        else{
            right--;
        }
        answer++;
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
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    char category[] = {'R', 'T', 'F', 'C', 'M', 'J', 'A', 'N'};
    map<char, int> mp;
    for(auto i : category){
        mp[i] = 0;
    }
    int len = survey.size();
    for(int i = 0; i < len; i++){
        int choice = choices[i];
        char left = survey[i][0];
        char right = survey[i][1];
        if(choice != 4){
            if(choice >= 1 && choice <= 3){
                mp[left] += abs(4 - choice);
            } else {
                mp[right] += abs(4 - choice);
            }
        }
    }
    answer += (mp['R'] >= mp['T']) ? 'R' : 'T';
    answer += (mp['C'] >= mp['F']) ? 'C' : 'F';
    answer += (mp['J'] >= mp['M']) ? 'J' : 'M';
    answer += (mp['A'] >= mp['N']) ? 'A' : 'N';
    
    return answer;
}
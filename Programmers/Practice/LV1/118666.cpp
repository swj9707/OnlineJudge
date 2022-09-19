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
                mp[left] += 4 - choice;
            } else {
                mp[right] += choice - 4;
            }
        }
    }
    if(mp['R'] >= mp['T']){
        answer += 'R';
    } else {
        answer += 'T';
    }
    
    if(mp['C'] >= mp['F']){
        answer += 'C';
    } else {
        answer += 'F';
    }
    
    if(mp['J'] >= mp['M']){
        answer += 'J';
    } else {
        answer += 'M';
    }
    
    if(mp['A'] >= mp['N']){
        answer += 'A';
    } else {
        answer += 'N';
    }
    
    return answer;
}
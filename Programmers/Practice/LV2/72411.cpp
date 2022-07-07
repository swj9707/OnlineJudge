#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> uom[11];

int maxCount[11];

void comb(string str, int cnt, string result){
    if(cnt == str.size()){
        int num = result.size();
        uom[num][result]++;
        maxCount[num] = max(maxCount[num], uom[num][result]);
        return;
    }

    comb(str, cnt+1, result + str[cnt]);
    comb(str, cnt+1, result);
}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto i : orders){
        sort(i.begin(), i.end());
        comb(i, 0, "");
    }

    for(auto i : course){
        for(auto j : uom[i]){
            if(j.second == maxCount[i] && j.second >= 2){
                answer.push_back(j.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
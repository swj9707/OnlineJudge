#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string returnGrade(float avg){
    if(avg >= 90) return "A";
    else if (avg >= 80 && avg < 90) return "B";
    else if (avg >= 70 && avg < 80) return "C";
    else if (avg >= 50 && avg < 70) return "D";
    else return "F";
}

string solution(vector<vector <int>> scores){
    string answer = "";
    for(int i = 0; i < scores.size(); i++){
        vector<int> data;
        int score = 0;
        for(int j = 0; j < scores[i].size(); j++) data.push_back(scores[j][i]);
        int max = *max_element(data.begin(), data.end());
        int maxIndex = max_element(data.begin(), data.end()) - data.begin();
        int min = *min_element(data.begin(), data.end());
        int minIndex = min_element(data.begin(), data.end()) - data.begin();
        int maxCount = count(data.begin(), data.end(), max);
        int minCount = count(data.begin(), data.end(), min);
        if(data[i] == max){
            if(maxCount == 1) data.erase(data.begin() + maxIndex);
        }
        else if(data[i] == min){
            if(minCount == 1) data.erase(data.begin() + minIndex);
        }
        score = float(accumulate(data.begin(), data.end(), 0) / data.size());
        answer += returnGrade(score);
    }
    return answer;
}
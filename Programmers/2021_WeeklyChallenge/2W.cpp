#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string returnGrade(int avg){
    if(avg >= 90) return "A";
    else if (avg >= 80 && avg < 90) return "B";
    else if (avg >= 70 && avg < 80) return "C";
    else if (avg >= 50 && avg < 70) return "D";
    else return "F";
}

string solution(vector<vector <int>> scores){
    string answer = "";
    vector<vector<int>> new_scores(scores.size(), vector<int> (scores.size()));
    int max, min, min_count, max_count, total, totalNum; 
    int score = 0;
    for(int i = 0; i < scores.size(); i++){
        for(int j = 0; j < scores[i].size(); j++) new_scores[i][j] = scores[j][i];
    }
    scores = new_scores;
    for(int i = 0; i < scores.size(); i++){
        min = *min_element(scores[i].begin(), scores[i].end());
        min_count = count(scores[i].begin(), scores[i].end(), min);
        max = *max_element(scores[i].begin(), scores[i].end());
        max_count = count(scores[i].begin(), scores[i].end(), max);
        total = accumulate(scores[i].begin(), scores[i].end(), 0);
        totalNum = scores[i].size();
        if((scores[i][i] == min && min_count == 1 || (scores[i][i] == max && max_count == 1))){
            total -= scores[i][i];
            totalNum -= 1;
        }
        total = (float)total / totalNum;
        answer += returnGrade(total);
    }
    return answer;
}
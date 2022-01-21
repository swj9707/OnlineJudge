#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> reportList;
map<string, int> userList;
vector<int> reportCount;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer, list;
    int length = id_list.size();
    list.reserve(length);
    reportList.resize(length, vector<bool>(length, false));
    reportCount.resize(length, 0);
    answer.resize(length, 0);

    for(int i = 0; i < length; i++){
        userList[id_list[i]] = i;   
    }

    for(auto i : report){
        istringstream ss(i);
        string tmp[2];
        ss >> tmp[0] >> tmp[1];

        string reporter = tmp[0];
        string respondent = tmp[1];
        reportList[userList[reporter]][userList[respondent]] = true;
    }

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length ; j++){
            if(reportList[i][j]) reportCount[j]++;
        }
    }

    for(int i = 0; i < length ; i++){
        if(reportCount[i] >= k) list.push_back(i);
    }

    for(int i = 0; i < length; i++){
        for(auto idx : list){
            if(reportList[i][idx]) answer[i] += 1;
        }
    }

    return answer;
}

int main(){
    for(auto i :  solution({"muzi", "frodo", "apeach", "neo"}, 
    {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2)){
        cout << i << " ";
    }
}
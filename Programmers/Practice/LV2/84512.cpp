#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string collec[5] = {"A", "I", "E", "O", "U"};
vector<string> vec;

void DFS(int length, string tmp){
    if(length == tmp.length()){
        vec.push_back(tmp);
        break;
    }
    for(int i = 0; i < 5; i++){
        DFS(length, tmp += collec[i]);
    }
}

int solution(string word) {
    int answer = 0;
    for(int i = 1; i <= 5; i++){
        DFS(i, "");
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++){
        if(vec[i] == word){
            answer = i + 1;
            break;
        }
    }

    return answer;
}
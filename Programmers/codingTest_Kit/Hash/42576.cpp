#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> d;
    for(auto& i : participant) d[i]++;
    for(auto& i : completion) d[i]--;
    for(auto& i : d){
        if(i.second > 0){
            answer = i.first;
            break;
        }
    }
    return answer;
}

int main(){
    cout << solution({"leo", "kiki", "eden"}, {"eden", "kiki"}) << '\n';
}
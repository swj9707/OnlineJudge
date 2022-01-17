#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    return answer;
}

int main(){
    for(auto i :  solution({"muzi", "frodo", "apeach", "neo"}, 
    {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2)){
        cout << i << " ";
    }
}
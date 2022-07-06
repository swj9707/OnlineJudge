#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool checkCondition(char opr, int num, int diff) {
        if(opr == '=') 
            return num == diff;
        else if(opr == '>') return diff > num;
        else return diff < num;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";
    sort(friends.begin(), friends.end());

    do{
        bool check = true;
        for(auto text : data){
            int firstIdx = friends.find(text[0]);
            int secondIdx = friends.find(text[2]);
            int diff = abs(firstIdx - secondIdx) - 1;
            int num = text[4] - '0';

            if(checkCondition(text[3], num, diff)) continue;
            check = false;
            break;
        }
        if(check) answer++;
    } while(next_permutation(friends.begin(), friends.end()));

    return answer;
}
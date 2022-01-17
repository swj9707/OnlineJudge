#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

string solution(string number, int k){
    string answer = "";
    int maxSize = number.length() - k;
    int start = 0;

    for(int i = 0; i < maxSize; i++){
        char maxNum = number[start];
        int maxIndex = start;
        for(int j = start; j <= k + i; j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                maxIndex = j;
            }
        }
        start = maxIndex + 1;
        answer += maxNum;
    }
    return answer;
}

int main(){
    cout << solution("1924", 2) << "\n";
    cout << solution("1231234", 3) << "\n";
    cout << solution("4177252841", 4) << "\n";
}
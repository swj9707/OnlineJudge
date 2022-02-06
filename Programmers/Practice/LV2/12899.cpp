#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string convertTernary(int n){
    string result = "";
    while(n != 0){
        int modResult = n % 3;
        if(n % 3 == 0) n -= 1;
        result += to_string(modResult);
        n /= 3;
    }
    return result;
}

string solution(int n) {
    string answer = "";
    string data[3] = {"4", "1", "2"};//3진법으로 일단 바꾸자.
    string result = convertTernary(n);
    for(int i = result.length() - 1; i >= 0; i--){
        
        answer += data[result[i] - '0'];
    }
    return answer;
}
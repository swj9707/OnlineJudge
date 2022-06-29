#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i = 1; i <= s.size() / 2; i++){
        int count = 1;
        string tmp = "";
        string substring = s.substr(0, i);
        for(int j = i; j < s.size(); j += i){
            if( substring == s.substr(j, i)) count++;
            else{
                if(count > 1) tmp += to_string(count);
                tmp += substring;
                substring = s.substr(j, i);
                count = 1;
            }
        }
        if(count > 1) tmp += to_string(count);
        tmp += substring;
        if(answer > tmp.size()) answer = tmp.size();
    }

    return answer;
}
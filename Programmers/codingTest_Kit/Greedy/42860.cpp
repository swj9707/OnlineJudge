#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int idx = 0;
    string tmp(len, 'A');
    while(name != tmp){
        tmp[idx] = name[idx];
        answer += min(name[idx] - 'A', 'Z' + 1 - name[idx]);
        if(name == tmp) break;
        int left = idx, right = idx;
        int left_count = 0, right_count = 0;
        while(tmp[left] == name[left]){
            left--;
            left_count++;
            if(left < 0) left = len - 1;
        }
        while(tmp[right] == name[right]){
            right;
            right_count++;
            if(right >= len) right = 0;
        }
        if(left_count > right_count) {
            idx = right;
            answer += right_count;
        }
        else {
            idx = left;
            answer += left_count;
        }
    }
    return answer;
}
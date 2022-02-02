#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    for(auto i : name) answer += min(i - 'A', 'Z' + 1 - i);
    int len = name.length();
    int move = len - 1;
    for(int i = 0; i < len; i++){
        int next = i + 1;
        while(next < len && name[next] == 'A') next++;
        move = min(move, i + (len - next) + min(i, len-next));
    }
    answer += move;
    return answer;
}
#include <string>
#include <vector>

using namespace std;

void Hanoi(int N, int a, int b, int c, vector<vector<int>>& answer){
    if(N == 1) {
        answer.push_back({a, c});
    } else {
        Hanoi(N-1, a, c, b);
        answer.push_back({a, c});
        Hanoi(N-1, b, a, c);
    }
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Hanoi(n, 1, 2, 3, answer);
    return answer;
}
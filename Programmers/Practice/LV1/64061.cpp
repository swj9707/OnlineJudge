#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> data;
    for(auto idx : moves){
        for(int i = 0; i < board.size(); i++){
            if(board[i][idx-1] != 0){
                data.push(board[i][idx-1]);
                board[i][idx-1] = 0;
                break;
            }
        }
        if(data.size() > 1){
            int first = data.top();
            data.pop();
            int second = data.top();
            data.pop();
            if(first == second) answer += 2;
            else{
                data.push(second);
                data.push(first);
            }
        }
    }
    return answer;
}
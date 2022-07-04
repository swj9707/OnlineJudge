#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = -1;
    int row = board.size();
    int col = board[0].size();
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(board[i][j] == 1){
                board[i][j] = 1 + min(board[i][j-1], min(board[i-1][j-1], board[i-1][j]));
                answer = max(board[i][j], answer);
            }
        }
    }

    return answer * answer;
}
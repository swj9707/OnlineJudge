package Programmers.Practice.LV1;

import java.util.*;

public class pg64061 {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;

        Stack<Integer> stack = new Stack<>();

        for(int idx : moves){
            for(int i = 0; i < board.length; i++){
                if(board[i][idx-1] != 0){
                    stack.push(board[i][idx-1]);
                    board[i][idx - 1] = 0;
                    break;
                }
            }

            if(stack.size() > 1){
                int first = stack.pop();
                int second = stack.pop();
                if(first == second) answer += 2;
                else{
                    stack.push(second);
                    stack.push(first);
                }
            }
        }

        return answer;
    }
}

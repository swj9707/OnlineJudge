package Programmers.codingTest_Kit.Stack_Queue;

import java.util.*;

public class pg42584 {
    public int[] solution(int[] prices) {
        int N = prices.length;
        int[] answer = new int[N];
        Stack<Integer> stack = new Stack<>();

        for(int i = 0; i < N; i++){
            while(!stack.empty() && prices[stack.peek()] > prices[i]){
                answer[stack.peek()] = i - stack.peek();
                stack.pop();
            }
            stack.add(i);
        }

        while(!stack.empty()){
            answer[stack.peek()] = N - stack.peek() - 1;
            stack.pop();
        }

        return answer;
    }
}

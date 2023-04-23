package Programmers.Practice.LV2;

import java.util.*;

class Solution {
    public int[] solution(int[] prices) {
        int N = prices.length;
        int[] answer = new int[N];

        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < N; i++) {
            while (!stk.isEmpty() && prices[stk.peek()] > prices[i]) {
                answer[stk.peek()] = i - stk.peek();
                stk.pop();
            }
            stk.add(i);
        }

        while (!stk.isEmpty()) {
            answer[stk.peek()] = N - stk.peek() - 1;
            stk.pop();
        }

        return answer;
    }
}

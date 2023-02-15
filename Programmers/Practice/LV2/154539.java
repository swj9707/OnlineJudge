package Programmers.Practice.LV2;

import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < numbers.length; i++) {
            if (stk.isEmpty() || numbers[i] < numbers[i - 1]) {
                stk.push(i);
            } else {
                while (!stk.isEmpty() && numbers[stk.peek()] < numbers[i]) {
                    answer[stk.pop()] = numbers[i];
                }
                stk.push(i);
            }
        }

        while (!stk.isEmpty()) {
            answer[stk.pop()] = -1;
        }

        return answer;
    }
}
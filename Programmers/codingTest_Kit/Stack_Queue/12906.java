package Programmers.codingTest_Kit.Stack_Queue;

import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            if (stack.isEmpty()) {
                stack.add(arr[i]);
            } else {
                if (stack.peek() != arr[i]) {
                    stack.add(arr[i]);
                }
            }
        }

        return stack.stream().mapToInt(Integer::intValue).toArray();
    }
}
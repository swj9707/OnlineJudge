package Programmers.Practice.LV2;

import java.util.Stack;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int len = s.length();

        Stack<Character> stk = new Stack<>();

        for (int i = 0; i < len; i++) {
            stk.clear();
            for (int j = 0; j < len; j++) {
                if (!stk.isEmpty()) {
                    if (stk.peek() == '[' && s.charAt(j) == ']') {
                        stk.pop();
                    } else if (stk.peek() == '(' && s.charAt(j) == ')') {
                        stk.pop();
                    } else if (stk.peek() == '{' && s.charAt(j) == '}') {
                        stk.pop();
                    } else {
                        stk.push(s.charAt(j));
                    }
                } else {
                    stk.push(s.charAt(j));
                }
            }

            if (stk.isEmpty()) {
                answer++;
            }

            char first = s.charAt(0);
            s = s.substring(1, len);
            s += first;
        }

        return answer;
    }
}
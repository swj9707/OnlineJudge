package Programmers.Practice.LV1;

import java.util.*;

class Solution {
    public String solution(String s, String skip, int index) {
        String answer = "";

        Set<Character> st = new HashSet<>();
        for (int i = 0; i < skip.length(); i++) {
            st.add(skip.charAt(i));
        }

        for (int i = 0; i < s.length(); i++) {
            char tmpChar = s.charAt(i);
            int count = 0;
            while (count < index) {
                tmpChar += 1;
                if (tmpChar > 'z') {
                    tmpChar = 'a';
                }
                if (st.contains(Character.valueOf(tmpChar))) {
                    continue;
                }
                count++;
            }

            answer += tmpChar;

        }
        return answer;
    }
}
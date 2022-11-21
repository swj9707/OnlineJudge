package Programmers.Practice.LV2;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = { 0, 0 };
        Set<String> set = new HashSet<>();

        set.add(words[0]);

        for (int i = 1; i < words.length; i++) {
            int order = i % n + 1;
            int seq = i / n + 1;

            char rear = words[i - 1].charAt(words[i - 1].length() - 1);
            char front = words[i].charAt(0);

            if (rear != front || set.contains(words[i])) {
                answer[0] = order;
                answer[1] = seq;
                break;
            } else {
                set.add(words[i]);
            }

        }

        return answer;
    }
}
package Programmers.Practice.LV2;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public int solution(int[] elements) {
        Set<Integer> st = new HashSet<>();

        for (int i = 1; i <= elements.length; i++) {
            for (int j = 0; j < elements.length; j++) {
                int sum = 0;
                for (int idx = j; idx < j + i; idx++) {
                    sum += elements[idx % elements.length];
                }
                st.add(sum);
            }
        }

        return st.size();
    }
}
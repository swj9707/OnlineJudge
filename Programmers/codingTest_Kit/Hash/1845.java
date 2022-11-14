package Programmers.codingTest_Kit.Hash;

import java.util.Arrays;
import java.util.Set;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[] nums) {
        Set<Integer> st = Arrays.stream(nums).boxed().collect(Collectors.toSet());
        if (st.size() >= nums.length / 2) {
            return nums.length / 2;
        } else {
            return st.size();
        }
    }
}
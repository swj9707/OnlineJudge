package Programmers.Practice.LV2;

import java.util.*;

class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] sumOf = new int[sequence.length];
        int arrLen = 99999999;

        for(int i = 0; i < sequence.length; i++){
            sumOf[i + 1] = sequence[i] + sumOf[i];
        }

        int left = 0, right = 0;
        int[] answer = new int[] {left, right};
        
        while(left <= right) {
            int sum = sumOf[right] - sumOf[left];
            
            if(sum == k) {
                int nowLen = right - 1 - left;
                if(nowLen < arrLen) {
                    arrLen = nowLen;
                    answer = new int[] {left, right - 1};
                }
            }

            if (sum < k) {
                right++;
            } else {
                left++;
            }
        }
        
        
        return answer;
    }
}
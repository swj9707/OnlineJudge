package Programmers.Practice.LV2;

import java.util.*;

class Solution {

    public int[] solution(int n, long k) {
        List<Integer> arr = new ArrayList<>();
        int[] answer = new int[n];
        long factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            arr.add(i);
        }
        k--;

        int idx = 0;
        while (n > 0) {
            factorial /= n;
            answer[idx++] = arr.get((int) (k / factorial));
            arr.remove((int) (k / factorial));
            k %= factorial;
            n--;
        }
        return answer;
    }

}
package Programmers.Practice.LV3;

import java.util.Arrays;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);

        int b = A.length - 1;
        for(int a = A.length - 1; a >= 0; a--){
            if(B[b] > A[a]){
                answer++;
                b--;
            }
        }

        return answer;
    }
}
package Programmers.Practice.LV2;

class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";

        String stringData = "";
        int maximum = t * m;

        for(int i = 0; i <= maximum; i++){
            stringData += Integer.toString(i, n);
        }
        stringData = stringData.toUpperCase();

        for(int i = 0; i < t; i++){
            answer += stringData.charAt(p - 1 + i * m);
        }

        return answer;
    }
}
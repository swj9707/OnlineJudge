package Programmers.Practice.LV1;

class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        long num = Long.parseLong(p);
        int lenofString = p.length();
        for(int i = 0; i < t.length() - lenofString + 1; i++){
            long tmpNum = Long.parseLong(t.substring(i, i + lenofString));
            if(num < tmpNum) {
                answer++;
            }
        }
        return answer;
    }
}
package LV2;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];

        while (!s.equals("1")) {
            answer[0]++;
            if (s.contains("0")) {
                answer[1] += (int) s.chars().filter(c -> c == '0').count();
                s = s.replace("0", "");
            }
            int len = s.length();
            s = Integer.toBinaryString(len);
        }

        return answer;
    }
}
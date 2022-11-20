package Programmers.Practice.LV1;

class Solution {
    public int solution(int number, int limit, int power) {
        int[] data = new int[number + 1];
        for (int i = 1; i <= number; i++) {
            for (int j = 1; j <= number / i; j++) {
                data[i * j]++;
            }
        }
        int answer = 0;
        for (int i = 1; i <= number; i++) {
            if (data[i] > limit) {
                answer += power;
            } else {
                answer += data[i];
            }
        }
        return answer;
    }
}
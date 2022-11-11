class Solution {
    public int solution(int[] numbers) {
        int answer = 0;

        for (int i = 0; i < numbers.length; i++) {
            for (int j = 0; j < i; j++) {
                answer = Math.max(answer, numbers[i] * numbers[j]);
            }
        }

        return answer;
    }
}
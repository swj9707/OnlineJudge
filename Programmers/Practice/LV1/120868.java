import java.util.Arrays;

class Solution {
    public int solution(int[] sides) {
        int answer = 0;
        int count = sides[0] + sides[1];

        Arrays.sort(sides);

        int maxValue = sides[1];
        int minValue = sides[0];

        // CASE 1 : 현재 값 중에서 가장 큰놈이 가장 큰 선분이라면?
        for (int i = 1; i < maxValue; i++) {
            if (maxValue < minValue + i) {
                answer++;
            }
        }

        // CASE 2 : 가장 큰 선분이 따로 있다면?
        for (int i = maxValue; i < count; i++) {
            if (i < count) {
                answer++;
            }
        }

        return answer;
    }
}
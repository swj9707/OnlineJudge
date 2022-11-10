import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        int len = numbers.length;
        Arrays.sort(numbers);
        answer = numbers[len - 1] * numbers[len - 2];

        return answer;
    }
}
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        Integer[] arr = Arrays.stream(citations).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, Collections.reverseOrder());

        if (arr[0] == 0) {
            return 0;
        }

        for (int i = 0; i < arr.length; i++) {
            if (citations[i] > i) {
                answer++;
            } else {
                break;
            }
        }

        return answer;
    }
}
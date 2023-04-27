package LV2;

import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> que = new ArrayDeque<>();
        List<Integer> answer = new ArrayList<>();

        for (int i = 0; i < progresses.length; i++) {
            int leftRate = 100 - progresses[i];
            int date = leftRate / speeds[i];
            if (leftRate % speeds[i] != 0) {
                date += 1;
            }

            que.add(date);
        }

        int start = que.peek();
        int count = 0;

        while (!que.isEmpty()) {
            if (que.peek() <= start) {
                que.remove();
                count++;
            } else {
                if (count > 0) {
                    start = que.peek();
                    answer.add(count);
                    count = 0;
                }
            }
        }

        answer.add(count);

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }

}
package Programmers.codingTest_Kit.Stack_Queue;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        Queue<Integer> q = new LinkedList<>();
        List<Integer> result = new ArrayList<>();

        for (int i = 0; i < progresses.length; i++) {
            int left = 100 - progresses[i];
            int date = left / speeds[i];
            if (left % speeds[i] != 0)
                date += 1;
            q.offer(date);
        }

        int startDate = q.peek();
        int count = 0;

        while (!q.isEmpty()) {
            if (q.peek() <= startDate) {
                q.remove();
                count++;
            } else {
                if (count > 0) {
                    startDate = q.peek();
                    result.add(count);
                    count = 0;
                }
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
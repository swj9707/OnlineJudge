import java.util.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        Arrays.sort(jobs, (x, y) -> (x[0] - y[0]));
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((x, y) -> x[1] - y[1]);
        int N = jobs.length;
        int time = 0, index = 0;
        while (!pq.isEmpty() || index < N) {

            while (index < N && jobs[index][0] <= time) {
                pq.add(jobs[index++]);
            }

            if (pq.isEmpty()) {
                time = jobs[index][0];
                continue;
            }

            int[] job = pq.poll();
            time += job[1];
            answer += time - job[0];

        }

        return answer / N;
    }
}
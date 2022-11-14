import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < scoville.length; i++) {
            pq.add(scoville[i]);
        }

        while (pq.size() > 1 && pq.peek() < K) {
            int first = pq.poll();
            int second = pq.poll();

            pq.add(first + 2 * second);
            answer++;
        }

        if (pq.size() <= 1 && pq.peek() < K) {
            answer = -1;
        }

        return answer;
    }
}
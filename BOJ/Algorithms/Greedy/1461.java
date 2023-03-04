package BOJ.Algorithms.Greedy;

import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int answer = 0;

        PriorityQueue<Integer> plusQueue = new PriorityQueue<>((p1, p2) -> p2 - p1);
        PriorityQueue<Integer> minusQueue = new PriorityQueue<>((p1, p2) -> p2 - p1);

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            if (tmp > 0) {
                plusQueue.offer(tmp);
            } else {
                minusQueue.offer(tmp * (-1));
            }
        }

        int maxValue = 0;

        if (plusQueue.isEmpty()) {
            maxValue = minusQueue.peek();
        } else if (minusQueue.isEmpty()) {
            maxValue = plusQueue.peek();
        } else {
            maxValue = Math.max(plusQueue.peek(), minusQueue.peek());
        }

        while (!plusQueue.isEmpty()) {
            int tmp = plusQueue.poll();
            for (int i = 0; i < M - 1; i++) {
                plusQueue.poll();
                if (plusQueue.isEmpty()) {
                    break;
                }
            }
            answer += tmp * 2;
        }

        while (!minusQueue.isEmpty()) {
            int tmp = minusQueue.poll();
            for (int i = 0; i < M - 1; i++) {
                minusQueue.poll();
                if (minusQueue.isEmpty()) {
                    break;
                }
            }
            answer += tmp * 2;
        }

        answer -= maxValue;

        bw.write(String.valueOf(answer));
        bw.flush();
    }

}

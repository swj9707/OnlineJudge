package BOJ.Algorithms.Greedy;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        PriorityQueue<Integer> pqPositive = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> pqNegative = new PriorityQueue<>();

        int answer = 0;

        for (int i = 0; i < N; i++) {
            int tmp = Integer.parseInt(br.readLine());
            if (tmp > 0) {
                pqPositive.add(tmp);
            } else {
                pqNegative.add(tmp);
            }
        }

        while (!pqPositive.isEmpty()) {
            int first = pqPositive.poll();
            int second = -1;
            if (!pqPositive.isEmpty()) {
                second = pqPositive.poll();
            }

            if (second != -1) {
                answer += Math.max(first * second, first + second);
            } else {
                answer += first;
            }
        }

        while (!pqNegative.isEmpty()) {
            int first = pqNegative.poll();
            int second = 1;
            if (!pqNegative.isEmpty()) {
                second = pqNegative.poll();
            }

            if (second != 1) {
                answer += Math.max(first * second, first + second);
            } else {
                answer += first;
            }
        }
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
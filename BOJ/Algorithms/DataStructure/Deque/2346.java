package BOJ.Algorithms.DataStructure.Deque;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        ArrayDeque<int[]> dq = new ArrayDeque<>();
        for (int i = 1; i <= N; i++) {
            int[] data = new int[] { i, Integer.parseInt(st.nextToken()) };
            dq.add(data);
        }

        while (dq.size() > 1) {
            int[] cur = dq.poll();
            sb.append(cur[0]).append(" ");

            int move = cur[1];

            if (move < 0) {
                while (move++ < 0) {
                    dq.addFirst(dq.pollLast());
                }
            } else {
                move--;
                while (move-- > 0) {
                    dq.addLast(dq.pollFirst());
                }
            }
        }

        sb.append(dq.poll()[0]);
        bw.write(sb.toString());
        bw.flush();
    }
}
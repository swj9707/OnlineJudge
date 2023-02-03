package BOJ.Algorithms.DataStructure.Deque;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(st.nextToken());
        for (int tc = 0; tc < T; tc++) {
            String functions = br.readLine();

            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine(), "[],");
            Deque<Integer> dq = new ArrayDeque<>();
            for (int i = 0; i < N; i++) {
                dq.add(Integer.parseInt(st.nextToken()));
            }

            boolean isRight = true;

            for (char cmd : functions.toCharArray()) {
                if (cmd == 'R') {
                    isRight = !isRight;
                    continue;
                }

                if (isRight) {
                    if (dq.pollFirst() == null) {
                        sb.append("error\n");
                        break;
                    }
                } else {
                    if (dq.pollLast() == null) {
                        sb.append("error\n");
                        break;
                    }
                }
            }

            if (!dq.isEmpty()) {
                sb.append("[");
                if (isRight) {
                    sb.append(dq.pollFirst());

                    while (!dq.isEmpty()) {
                        sb.append(',').append(dq.pollFirst());
                    }
                } else {
                    sb.append(dq.pollLast());

                    while (!dq.isEmpty()) {
                        sb.append(',').append(dq.pollFirst());
                    }
                }
                sb.append(']').append('\n');
            }
        }
        bw.write(sb.toString());
        bw.flush();
    }
}
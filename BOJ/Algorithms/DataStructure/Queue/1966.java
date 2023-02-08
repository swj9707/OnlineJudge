package BOJ.Algorithms.DataStructure.Queue;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            ArrayDeque<int[]> printer = new ArrayDeque<>();
            PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                int x = Integer.parseInt(st.nextToken());
                printer.add(new int[] { x, i });
                pq.add(x);
            }

            int count = 0;

            while (!printer.isEmpty()) {
                int[] tmp = printer.poll();
                if (tmp[0] == pq.peek()) {
                    pq.poll();
                    count++;
                    if (tmp[1] == M) {
                        bw.write(String.valueOf(count) + "\n");
                        break;
                    }
                } else {
                    printer.add(tmp);
                }
            }
        }
        bw.flush();
    }
}

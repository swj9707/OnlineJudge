package Softeer.LV2;

import java.io.*;
import java.util.*;

class Pair implements Comparable<Pair> {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair o) {
        return this.second < o.second ? 1 : -1;
    }
}

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int W, N;
        int result = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();

        W = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int first, second;
            first = Integer.parseInt(st.nextToken());
            second = Integer.parseInt(st.nextToken());
            pq.offer(new Pair(first, second));
        }

        while (!pq.isEmpty()) {
            Pair pair = pq.poll();
            if (W < pair.first) {
                result = result + W * pair.second;
                break;
            } else {
                result = result + pair.first * pair.second;
                W = W - pair.first;
            }
        }

        bw.write(String.valueOf(result));
        bw.flush();
    }

}

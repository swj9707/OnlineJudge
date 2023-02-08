package Programmers.codingTest_Kit.Search;

import java.util.*;
import java.io.*;

class Main {
    static int[][] arr;
    static boolean[] VISIT;
    static int minVal = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        arr = new int[N][2];
        VISIT = new boolean[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        DFS(0);
        bw.write(String.valueOf(minVal));
        bw.flush();
    }

    public static void DFS(int current) {
        if (current == arr.length) {
            int sour = 1;
            int bitter = 0;
            int count = 0;

            for (int i = 0; i < VISIT.length; i++) {
                if (VISIT[i]) {
                    count++;
                    sour *= arr[i][0];
                    bitter += arr[i][1];
                }
            }
            if (count == 0)
                return;
            minVal = Math.min(minVal, Math.abs(sour - bitter));
            return;
        }

        VISIT[current] = true;
        DFS(current + 1);
        VISIT[current] = false;
        DFS(current + 1);
    }

}
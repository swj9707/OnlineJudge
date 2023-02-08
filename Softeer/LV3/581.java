package Softeer.LV3;

import java.util.*;
import java.io.*;

class Main {
    static boolean[] VISIT = new boolean[11];
    static int[] MATRIX = new int[11];
    static int result = 99999999;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] railData = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            railData[i] = Integer.parseInt(st.nextToken());
        }

        DFS(0, N, M, K, railData);
        bw.write(String.valueOf(result));
        bw.flush();
    }

    public static void DFS(int count, int N, int M, int K, int[] railData) {
        if (count == N) {
            int idx = 0;
            int bucket = 0;
            int sumOfData = 0;

            for (int work = 0; work < K; work++) {
                while (MATRIX[idx] + bucket <= M) {
                    bucket += MATRIX[idx];
                    idx = (idx + 1) % N;
                }
                sumOfData += bucket;
                bucket = 0;
            }
            result = Math.min(sumOfData, result);
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (!VISIT[i]) {
                VISIT[i] = true;
                MATRIX[count] = railData[i];
                DFS(count + 1, N, M, K, railData);
                VISIT[i] = false;
            }
        }
    }
}
package BOJ.Algorithms.DynamicProgramming;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] arr = new int[N + 1];
        int[] DP = new int[K + 1];
        DP[0] = 1;
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            for (int j = arr[i]; j <= K; j++) {
                DP[j] += DP[j - arr[i]];
            }
        }

        bw.write(String.valueOf(DP[K]));
        bw.flush();
    }
}
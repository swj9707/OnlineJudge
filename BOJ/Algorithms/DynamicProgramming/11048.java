package BOJ.Algorithms.DynamicProgramming;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        int[][] MATRIX = new int[N + 1][M + 1];
        int result = -1;

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= M; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
                result = Math.max(MATRIX[i][j - 1], Math.max(MATRIX[i-1][j-1], MATRIX[i - 1][j]));
                MATRIX[i][j] += result;
            }
        }

        bw.write(String.valueOf(MATRIX[N][M]));
        bw.flush();

    }
}
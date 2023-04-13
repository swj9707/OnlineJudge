package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        int[][] MATRIX = new int[N][M];

        int count = Math.min(M, N) / 2;

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < count; j++) {

                int tmp = MATRIX[j][j];

                for(int k = j + 1; k < M - j; k++) 
                    MATRIX[j][k - 1] = MATRIX[j][k];

                for(int k = j + 1; k < N - j ; k++)
					MATRIX[k - 1][M - 1 - j] = MATRIX[k][M - 1 - j];
				
				for(int k = M - 2 - j; k >= j; k--)
                    MATRIX[N - 1 - j][k + 1] = MATRIX[N - 1 -j][k];
				
				for(int k= N - 2 - j; k >= j; k--)
                    MATRIX[k + 1][j] = MATRIX[k][j];
				
				MATRIX[j + 1][j] = tmp;

            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                bw.write(String.valueOf(MATRIX[i][j]) + " ");
            }
            bw.write("\n");
        }

        bw.flush();

    }
}
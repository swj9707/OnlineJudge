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
        Queue<Integer> que = new ArrayDeque<>();

        int[][] MATRIX = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < R; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            que.add(tmp);
        }

        while (!que.isEmpty()) {
            int oper = que.poll();
            switch (oper) {
                case 1:
                    operOne(MATRIX, N, M);
                    break;
                case 2:
                    operTwo(MATRIX, N, M);
                    break;
                case 3:
                    operThree(MATRIX, N, M);
                    break;
                case 4:
                    operFour(MATRIX, N, M);
                    break;
                case 5:
                    operFive(MATRIX, N, M);
                    break;
                case 6:
                    operSix(MATRIX, N, M);
                    break;
                default:
                    break;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                bw.write(String.valueOf(MATRIX[i][j]) + " ");
            }
            bw.write("\n");
        }

        bw.flush();

    }

    public static void swap(int a, int b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    public static void operOne(int[][] MATRIX, int N, int M) {

        int[][] newMAT = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                newMAT[N - i - 1][j] = MATRIX[i][j];
            }
        }

        MATRIX = newMAT;

    }

    public static void operTwo(int[][] MATRIX, int N, int M) {

        int[][] newMat = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                newMat[i][M - j - 1] = MATRIX[i][j];
            }
        }

        MATRIX = newMat;

    }

    public static void operThree(int[][] MATRIX, int N, int M) {

        int[][] newMap = new int[N][M];

        int C = N - 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                newMap[j][C] = MATRIX[i][j];
            }
            C--;
        }
        int tmp = N;
        N = M;
        M = tmp;
        MATRIX = newMap;
    }

    public static void operFour(int[][] MATRIX, int N, int M) {

        int[][] newMap = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                newMap[M - j - 1][i] = MATRIX[i][j];
            }
        }
        int tmp = N;
        N = M;
        M = tmp;
        MATRIX = newMap;

    }

    public static void operFive(int[][] MATRIX, int N, int M) {

    }

    public static void operSix(int[][] MATRIX, int N, int M) {

    }

}
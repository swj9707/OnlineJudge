package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {

    public static int[][] MATRIX;
    public static int N;
    public static int M;

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

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        MATRIX = new int[N][M];

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        List<Integer> operList = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < R; i++) {
            operList.add(Integer.parseInt(st.nextToken()));
        }

        for(int i = 0; i < operList.size(); i++) {
            int oper = operList.get(i);
            switch(oper) {
                case 1 : 
                    operOne();
                    break;
                case 2 : 
                    operTwo();
                    break;
                case 3 :
                    operThree();
                    break;
                case 4 : 
                    operFour();
                    break;
                case 5 :
                    operFive();
                    break;
                case 6 :
                    operSix();
                    break;
                default : 
                    break;
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

    public static void operOne() {
        int[][] nextMat = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                nextMat[N - i - 1][j] = MATRIX[i][j];
            }
        }

        MATRIX = nextMat;

    }

    public static void operTwo() {
        int[][] nextMat = new int[N][M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                nextMat[i][M - j - 1] = MATRIX[i][j];
            }
        }

        MATRIX = nextMat;
    }

    public static void operThree() {
        int[][] nextMat = new int[M][N];

        int C = N - 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                nextMat[j][C] = MATRIX[i][j];
            }
            C--;
        }

        int tmp = N;
        N = M;
        M = tmp;

        MATRIX = nextMat;

    }

    public static void operFour() {

        int[][] nextMat = new int[M][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                nextMat[M - j - 1][i] = MATRIX[i][j];
            }

        }

        int tmp = N;
        N = M;
        M = tmp;

        MATRIX = nextMat;

    }

    public static void operFive() {

        int[][] nextMat = new int[N][M];

        int nMid = N / 2;
        int mMid = M / 2;

        for (int i = 0; i < nMid; i++) {
            for (int j = 0; j < mMid; j++) {
                nextMat[i][mMid + j] = MATRIX[i][j];
            }
        }

        for (int i = 0; i < nMid; i++) {
            for (int j = 0; j < mMid; j++) {
                nextMat[nMid + i][j] = MATRIX[i][j];
            }
        }

        for (int i = 0; i < nMid; i++) {
            int C = 0;
            for (int j = mMid; j < M; j++, C++) {
                nextMat[i][C] = MATRIX[i][j];
            }
        }

        int row = 0;

        for (int i = nMid; i < N; i++, row++) {
            for (int j = 0; j < mMid; j++) {
                nextMat[row][j] = MATRIX[i][j];
            }
        }

        MATRIX = nextMat;

    }

    public static void operSix() {

        int[][] nextMat = new int[N][M];

        int nMid = N / 2;
        int mMid = M / 2;

        for (int i = 0; i < nMid; i++) {
            for (int j = 0; j < mMid; j++) {
                nextMat[nMid + i][j] = MATRIX[i][j];
            }
        }

        for (int i = nMid; i < N; i++) {
            for (int j = 0; j < mMid; j++) {
                nextMat[i][mMid + j] = MATRIX[i][j];
            }
        }

        int row = 0;

        for (int i = nMid; i < N; i++, row++) {
            for (int j = mMid; j < M; j++) {
                nextMat[row][j] = MATRIX[i][j];
            }
        }

        for (int i = 0; i < nMid; i++, row++) {
            int C = 0;
            for (int j = mMid; j < M; j++, C++) {
                nextMat[i][C] = MATRIX[i][j];
            }
        }

        MATRIX = nextMat;
    }

}
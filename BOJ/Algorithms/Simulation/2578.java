package BOJ.Algorithms.Simulation;

import java.io.*;
import java.util.*;

class Main {

    static int[][] MATRIX = new int[5][5];
    static int[][] board = new int[5][5];
    static int count;
    public static void main(String[] args) throws Exception {
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        for(int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 5; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < 5; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
             }
        }

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                answer++;
                count = 0;
                for(int x = 0; x < 5; x++) {
                    for(int y = 0; y < 5; y++) {
                        if(MATRIX[x][y] == board[i][j]) {
                            MATRIX[x][y] = 0;
                        }
                    }
                }


                rCheck();
                cCheck();
                lrCheck();
                rlCheck();
                if(count >= 3) {
                    bw.write(String.valueOf(answer));
                    bw.flush();
                    return;
                }
            }
        }
    }

    public static void rCheck() {
        for(int i = 0; i < 5; i++) {
            int zeroCount = 0;
            for(int j = 0; j < 5; j++) {
                if(MATRIX[i][j] == 0)
                    zeroCount++;
            }
            if(zeroCount == 5)
                count++;
        }
    }

    public static void cCheck() {
        for(int i = 0; i < 5; i++) {
            int zeroCount = 0;
            for(int j = 0; j < 5; j++) {
                if(MATRIX[j][i] == 0)
                    zeroCount++;
            }
            if(zeroCount == 5)
                count++;
        }
    }

    public static void lrCheck() {
        int zeroCount = 0;
        for(int i = 0; i < 5; i++) {
            if(MATRIX[i][i] == 0)
                zeroCount++;
        }
        if(zeroCount == 5)
            count++;
    }

    public static void rlCheck() {
        int zeroCount = 0;
        for(int i = 0; i < 5; i++) {
            if(MATRIX[i][4-i] == 0)
                zeroCount++;
        }
        if(zeroCount == 5)
            count++;
    }
}

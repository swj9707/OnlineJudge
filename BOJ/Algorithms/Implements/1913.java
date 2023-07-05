package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {

    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[][] MATRIX = new int[N][N];
        int x = 0, y = 0;
        int num = N * N;
        int direction = 0;
        int ansX = 0, ansY = 0;
        while (true) {
            if (num == 0) {
                break;
            }
            MATRIX[x][y] = num--;

            if (MATRIX[x][y] == M) {
                ansX = x;
                ansY = y;
            }

            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if ((nx >= N || ny >= N || nx < 0 || ny < 0) || MATRIX[nx][ny] != 0) {
                direction = (direction + 1) % 4;
                nx = x + dx[direction];
                ny = y + dy[direction];
            }

            x = nx;
            y = ny;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(String.valueOf(MATRIX[i][j])).append(" ");
            }
            sb.append("\n");
        }

        sb.append(ansX + 1).append(" ").append(ansY + 1);
        bw.write(sb.toString());
        bw.flush();
    }
}
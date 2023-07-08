package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {
    static char[][] MATRIX = new char[10][10];
    static char[][] ANSWER = new char[10][10];
    static int[] dx = { 0, 0, 1, -1, 1, -1, 1, -1 };
    static int[] dy = { 1, -1, 0, 0, 1, -1, -1, 1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        Queue<int[]> que = new ArrayDeque<>();
        Queue<int[]> mineQue = new ArrayDeque<>();
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < N; j++) {
                MATRIX[i][j] = tmp.charAt(j);
                if (MATRIX[i][j] == '*') {
                    mineQue.add(new int[] { i, j });
                }
            }
        }

        boolean check = false;

        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < N; j++) {
                ANSWER[i][j] = tmp.charAt(j);
                if (tmp.charAt(j) == 'x') {
                    que.add(new int[] { i, j });
                    if (MATRIX[i][j] == '*') {
                        check = true;
                    }
                }
            }
        }

        while (!que.isEmpty()) {
            int[] tmp = que.poll();
            int X = tmp[0];
            int Y = tmp[1];
            int count = 0;
            for (int i = 0; i < 8; i++) {
                int nx = X + dx[i];
                int ny = Y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (MATRIX[nx][ny] == '*') {
                        count++;
                    }
                }
            }
            ANSWER[X][Y] = (char) (count + '0');
        }

        if (check) {
            while (!mineQue.isEmpty()) {
                int[] tmp = mineQue.poll();
                int X = tmp[0];
                int Y = tmp[1];
                ANSWER[X][Y] = '*';
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sb.append(ANSWER[i][j]);
            }
            sb.append("\n");
        }

        bw.write(sb.toString());
        bw.flush();

    }
}
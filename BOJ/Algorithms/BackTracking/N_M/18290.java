package BOJ.Algorithms.BackTracking.N_M;

import java.io.*;
import java.util.*;

class Main {
    static int[][] MATRIX = new int[10][10];
    static boolean[][] visit = new boolean[10][10];
    static int[] dx = new int[] { 0, 0, 1, -1 };
    static int[] dy = new int[] { 1, -1, 0, 0 };
    static int result = -1;
    static int N;
    static int M;
    static int K;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visit[i][j] = true;
                DFS(1, MATRIX[i][j], i, j);
                visit[i][j] = false;
            }
        }

        bw.write(String.valueOf(result));
        bw.flush();
    }

    public static void DFS(int count, int sum, int x, int y) {
        if (count == K) {
            result = Math.max(result, sum);
            return;
        }

        for (int i = x; i < N; i++) {
            for (int j = y; j < M; j++) {
                boolean check = true;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j = dy[k];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && visit[nx][ny] == true) {
                        check = false;
                    }
                }
                if (!check) {
                    visit[i][j] = true;
                    DFS(count + 1, sum + MATRIX[i][j], i, j);
                    visit[i][j] = false;
                }
            }
        }
    }
}
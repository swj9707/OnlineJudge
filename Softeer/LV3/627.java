package Softeer.LV3;

import java.io.*;
import java.util.*;

class Main {
    static int[][] MATRIX = new int[129][129];
    static boolean[][] VISIT = new boolean[129][129];
    static int[] dx = { 1, -1, 0, 0 };
    static int[] dy = { 0, 0, 1, -1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= H; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= W; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        int Q = Integer.parseInt(st.nextToken());

        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            BFS(i, j, H, W, c);
        }

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                bw.write(String.valueOf(MATRIX[i][j] + " "));
            }
            bw.write("\n");
        }
        bw.flush();
    }

    public static void initData() {
        for (int i = 0; i < 129; i++) {
            for (int j = 0; j < 129; j++) {
                VISIT[i][j] = false;
            }
        }
    }

    public static void BFS(int x, int y, int H, int W, int c) {
        initData();
        Queue<int[]> que = new LinkedList<>();

        que.add(new int[] { x, y });
        VISIT[x][y] = true;
        int color = MATRIX[x][y];
        MATRIX[x][y] = c;

        while (!que.isEmpty()) {
            int X = que.peek()[0];
            int Y = que.peek()[1];
            que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = X + dx[i];
                int ny = Y + dy[i];

                if (nx > 0 && nx <= H && ny > 0 && ny <= W && !VISIT[nx][ny] && MATRIX[nx][ny] == color) {
                    VISIT[nx][ny] = true;
                    MATRIX[nx][ny] = c;
                    que.add(new int[] { nx, ny });
                }
            }
        }

    }
}
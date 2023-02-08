package Softeer.LV3;

import java.util.*;
import java.io.*;

class Main {
    static char[][] MATRIX = new char[51][51];
    static boolean[][] VISIT = new boolean[51][51];
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };
    static Set<int[]> rainSet = new HashSet<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int startX = 0;
        int startY = 0;
        for (int i = 1; i <= R; i++) {
            st = new StringTokenizer(br.readLine());
            String tmp = st.nextToken();
            for (int j = 1; j <= C; j++) {
                MATRIX[i][j] = tmp.charAt(j - 1);
                if (MATRIX[i][j] == 'W') {
                    startX = i;
                    startY = j;
                } else if (MATRIX[i][j] == '*') {
                    rainSet.add(new int[] { i, j });
                }
            }
        }
        int result = BFS(startX, startY, R, C);
        if (result == -1) {
            bw.write("FAIL");
        } else {
            bw.write(String.valueOf(result));
        }
        bw.flush();
    }

    public static void Shower(int R, int C) {
        List<int[]> tmp = new ArrayList<>();
        for (int[] X : rainSet) {
            for (int i = 0; i < 4; i++) {
                int nx = X[0] + dx[i];
                int ny = X[1] + dy[i];

                if (nx > 0 && nx <= R && ny > 0 && ny <= C && MATRIX[nx][ny] == '.') {
                    MATRIX[nx][ny] = '*';
                    tmp.add(new int[] { nx, ny });
                }
            }
        }

        for (int[] x : tmp) {
            rainSet.add(x);
        }
    }

    public static int BFS(int X, int Y, int R, int C) {
        int result = -1;

        Queue<int[]> que = new LinkedList<>();
        que.add(new int[] { X, Y, 0 });
        VISIT[X][Y] = true;
        int tmp = 0;
        Shower(R, C);

        while (!que.isEmpty()) {
            int x = que.peek()[0];
            int y = que.peek()[1];
            int count = que.peek()[2];
            que.poll();

            if (tmp != count) {
                Shower(R, C);
            }
            tmp = count;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx > 0 && nx <= R && ny > 0 && ny <= C && !VISIT[nx][ny] && MATRIX[nx][ny] != '*'
                        && MATRIX[nx][ny] != 'X') {
                    VISIT[nx][ny] = true;
                    if (MATRIX[nx][ny] == 'H') {
                        return count + 1;
                    }
                    que.add(new int[] { nx, ny, count + 1 });
                }
            }
        }

        return result;
    }
}
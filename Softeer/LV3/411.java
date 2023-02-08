package Softeer.LV3;

import java.util.*;
import java.io.*;

class Main {
    static int[][] MATRIX = new int[101][101];
    static boolean[][] VISIT = new boolean[101][101];
    static int[][] MAP = new int[101][101];
    static int countOfIce = 0;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= M; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
                if (MATRIX[i][j] == 1) {
                    countOfIce++;
                }
            }
        }

        bw.write(String.valueOf(BFS(N, M)));
        bw.flush();

    }

    public static void initSetup(int N, int M) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                MAP[i][j] = MATRIX[i][j];
                VISIT[i][j] = false;
            }
        }
    }

    public static void checkMap(int N, int M) {
        Queue<int[]> que = new LinkedList<>();
        VISIT[1][1] = true;
        que.add(new int[] { 1, 1 });

        while (!que.isEmpty()) {
            int X = que.peek()[0];
            int Y = que.peek()[1];
            que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = X + dx[i];
                int ny = Y + dy[i];

                while (nx > 0 && nx <= N && ny > 0 && ny <= M && !VISIT[nx][ny] && MAP[nx][ny] == 0) {
                    VISIT[nx][ny] = true;
                    que.add(new int[] { nx, ny });
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (!VISIT[i][j] && MAP[i][j] == 0) {
                    MAP[i][j] = -1;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (MAP[i][j] == 1) {
                    int count = 0;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx > 0 && nx <= N && ny > 0 && ny <= M && VISIT[nx][ny]) {
                            count++;
                        }
                    }
                    if (count >= 2) {
                        MATRIX[i][j] = 0;
                        countOfIce--;
                    }
                }
            }
        }
    }

    public static int BFS(int N, int M) {
        int result = 0;

        while (countOfIce != 0) {
            initSetup(N, M);
            checkMap(N, M);
            result++;
        }

        return result;
    }

}
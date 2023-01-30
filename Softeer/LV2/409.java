package Softeer.LV2;

import java.util.*;
import java.io.*;

class Pair {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Main {
    static int[][] MATRIX = new int[26][26];
    static boolean[][] VISIT = new boolean[26][26];
    static int[] dx = new int[] { 0, 0, 1, -1 };
    static int[] dy = new int[] { 1, -1, 0, 0 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        List<Integer> result = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            String row = br.readLine();
            for (int j = 1; j <= N; j++) {
                MATRIX[i][j] = row.charAt(j - 1) - '0';
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (MATRIX[i][j] == 1 && !VISIT[i][j]) {
                    int res = BFS(i, j, N);
                    result.add(res);
                }
            }
        }
        Collections.sort(result);
        bw.write(String.valueOf(result.size()));
        bw.newLine();
        for (int x : result) {
            bw.write(String.valueOf(x));
            bw.newLine();
        }
        bw.flush();
    }

    public static int BFS(int x, int y, int N) {
        int result = 1;
        Queue<Pair> que = new LinkedList<>();
        que.add(new Pair(x, y));
        VISIT[x][y] = true;

        while (!que.isEmpty()) {
            int X = que.peek().first;
            int Y = que.peek().second;
            que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = X + dx[i];
                int ny = Y + dy[i];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && !VISIT[nx][ny] && MATRIX[nx][ny] == 1) {
                    que.add(new Pair(nx, ny));
                    VISIT[nx][ny] = true;
                    result++;
                }
            }

        }

        return result;
    }
}
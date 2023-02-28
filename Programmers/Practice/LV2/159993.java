package Programmers.Practice.LV2;

import java.util.*;

class Solution {

    static char[][] MATRIX = new char[101][101];
    static int[][] VISIT = new int[101][101];
    static final int[] dx = new int[] { 0, 0, 1, -1 };
    static final int[] dy = new int[] { 1, -1, 0, 0 };

    public int solution(String[] maps) {
        int answer = 0;

        int startX = 0, startY = 0;
        int destX = 0, destY = 0;
        int N = maps.length;
        int M = maps[0].length();

        for (int i = 1; i <= maps.length; i++) {
            for (int j = 1; j < maps[0].length(); j++) {
                char tmp = maps[i].charAt(j - 1);
                MATRIX[i][j] = tmp;
                if (tmp == 'S') {
                    startX = i;
                    startY = j;
                } else if (tmp == 'E') {
                    destX = i;
                    destY = j;
                }
            }
        }

        answer = BFS(startX, startY, destX, destY, N, M);

        return answer;
    }

    public static int BFS(int startX, int startY, int destX, int destY, int N, int M) {
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[] { startX, startY });
        VISIT[startX][startY] = 0;

        while (!que.isEmpty()) {
            int X = que.peek()[0];
            int Y = que.peek()[1];

            if (X == destX && Y == destY) {
                return VISIT[X][Y];
            }

            que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = X + dx[i];
                int ny = Y + dy[i];

                if (nx > 0 && nx <= N && ny > 0 && ny <= M && VISIT[nx][ny] == 0 && MATRIX[nx][ny] != 'X') {
                    VISIT[nx][ny] = VISIT[X][Y] + 1;
                    que.add(new int[] { nx, ny });
                }
            }
        }

        return -1;
    }
}
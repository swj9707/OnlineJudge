package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {
    static char[][] MATRIX;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int[] answer = new int[5];
        int N = Integer.parseInt(br.readLine());
        MATRIX = new char[N][N];
        int[] core = new int[2];
        int legStart = 0;
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < N; j++) {
                MATRIX[i][j] = tmp.charAt(j);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (MATRIX[i][j] == '*') {
                    int count = 0;
                    for (int x = 0; x < 4; x++) {
                        int nx = i + dx[x];
                        int ny = j + dy[x];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                            if (MATRIX[nx][ny] == '*') {
                                count++;
                            }
                        }
                    }
                    if (count == 4) {
                        core[0] = i;
                        core[1] = j;
                        break;
                    }
                }
            }
        }

        for (int j = core[1] - 1; j >= 0; j--) {
            if (MATRIX[core[0]][j] == '*') {
                answer[0]++;
            } else {
                break;
            }
        }

        for (int j = core[1] + 1; j < N; j++) {
            if (MATRIX[core[0]][j] == '*') {
                answer[1]++;
            } else {
                break;
            }
        }

        for (int i = core[0] + 1; i < N; i++) {
            if (MATRIX[i][core[1]] == '*') {
                answer[2]++;
            } else {
                legStart = i;
                break;
            }
        }

        for (int i = legStart; i < N; i++) {
            if (MATRIX[i][core[1] - 1] == '*') {
                answer[3]++;
            } else {
                break;
            }
        }

        for (int i = legStart; i < N; i++) {
            if (MATRIX[i][core[1] + 1] == '*') {
                answer[4]++;
            } else {
                break;
            }
        }

        bw.write(String.valueOf(core[0] + 1) + " " + String.valueOf(core[1] + 1) + '\n');
        for (int i = 0; i < 5; i++) {
            bw.write(answer[i] + " ");
        }
        bw.write("\n");
        bw.flush();
    }
}
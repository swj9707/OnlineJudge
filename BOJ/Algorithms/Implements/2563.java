package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {
    static int[][] MATRIX = new int[100][100];
    static int amount = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int X = Integer.parseInt(st.nextToken());
            int Y = Integer.parseInt(st.nextToken());
            for (int x = X; x < X + 10; x++) {
                for (int y = Y; y < Y + 10; y++) {
                    if (MATRIX[x][y] == 0) {
                        MATRIX[x][y] = 1;
                        amount++;
                    }
                }
            }
        }

        bw.write(String.valueOf(amount));
        bw.flush();
    }
}

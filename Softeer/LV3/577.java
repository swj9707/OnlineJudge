package Softeer.LV3;

import java.io.*;
import java.util.*;

class Main {
    static char[][] MATRIX = new char[26][26];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= H; i++) {
            String tmp = br.readLine();
            for (int j = 1; j <= W; j++) {
                MATRIX[i][j] = tmp.charAt(j - 1);
            }
        }
    }
}

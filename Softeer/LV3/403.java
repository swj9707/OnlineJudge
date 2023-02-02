package Softeer.LV3;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        int[][] asmLineA = new int[N + 1][2];
        int[][] asmLineB = new int[N + 1][2];

        int[][] DPTable = new int[N + 1][2];
        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            asmLineA[i][0] = Integer.parseInt(st.nextToken());
            asmLineB[i][0] = Integer.parseInt(st.nextToken());
            asmLineA[i][1] = Integer.parseInt(st.nextToken());
            asmLineB[i][1] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        asmLineA[N][0] = Integer.parseInt(st.nextToken());
        asmLineB[N][0] = Integer.parseInt(st.nextToken());

        DPTable[1][0] = asmLineA[1][0];
        DPTable[1][1] = asmLineB[1][0];

        for (int i = 2; i <= N; i++) {
            DPTable[i][0] = Math.min(DPTable[i - 1][0], DPTable[i - 1][1] + asmLineB[i - 1][1]) + asmLineA[i][0];
            DPTable[i][1] = Math.min(DPTable[i - 1][1], DPTable[i - 1][0] + asmLineA[i - 1][1]) + asmLineB[i][0];
        }

        bw.write(String.valueOf(Math.min(DPTable[N][0], DPTable[N][1])));
        bw.flush();
    }
}
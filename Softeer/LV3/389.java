package Softeer.LV3;

import java.util.*;
import java.io.*;

class Main {
    static int[] arr = new int[1000001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N, K;
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int A, B;
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            long sum = 0;
            for (int j = A; j <= B; j++) {
                sum += arr[j];
            }
            double avg = (sum) / (B - A + 1);
            String result = String.format("%.2f", avg);
            bw.write(String.valueOf(result));
            bw.newLine();
        }
        bw.flush();
    }
}

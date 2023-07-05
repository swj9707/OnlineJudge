package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int maxW = Integer.MIN_VALUE, maxH = Integer.MIN_VALUE;
        int maxWIdx = -1, maxHIdx = -1;
        int[] arr = new int[6];
        for (int i = 0; i < 6; i++) {
            st = new StringTokenizer(br.readLine());
            int direction = Integer.parseInt(st.nextToken());
            int length = Integer.parseInt(st.nextToken());
            if (direction == 2 || direction == 1) {
                if (maxW < length) {
                    maxW = length;
                    maxWIdx = i;
                }
            } else {
                if (maxH < length) {
                    maxH = length;
                    maxHIdx = i;
                }
            }
            arr[i] = length;
        }

        int maxSq = maxH * maxW;
        int minSq = arr[(maxHIdx + 3) % 6] * arr[(maxWIdx + 3) % 6];
        int answer = (maxSq - minSq) * N;
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
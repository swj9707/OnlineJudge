package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[] arr = new int[M];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0, right = N;
        int mid, ans = 0;

        while (left <= right) {
            mid = (left + right) / 2;
            if (isPossible(arr, N, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();

    }

    public static boolean isPossible(int[] arr, int n, int h) {
        int len = arr.length;
        int darkStart = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] - h <= darkStart) {
                darkStart = arr[i] + h;
            } else
                break;
        }

        return n - darkStart <= 0;
    }

}

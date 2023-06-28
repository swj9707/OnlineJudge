package BOJ.Algorithms.SlidingWindow;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] sumArr = new int[N];
        sumArr[0] = arr[0];
        for (int i = 1; i < N; i++) {
            sumArr[i] = arr[i] + sumArr[i - 1];
        }

        int left = -1, right = X - 1;
        int max = Integer.MIN_VALUE;
        int sum = sumArr[right];
        int count = 1;

        while (right < N) {
            if (max == sum) {
                count++;
            } else if (max < sum) {
                max = sum;
                count = 1;
            }
            right++;
            left++;
            if (right < N) {
                sum = sumArr[right] - sumArr[left];
            }
        }
        if (max == 0) {
            bw.write("SAD");
        } else {
            bw.write(String.valueOf(max) + "\n");
            bw.write(String.valueOf(count) + '\n');
        }

        bw.flush();
    }
}
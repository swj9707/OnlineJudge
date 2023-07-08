package BOJ.Algorithms.BinarySearch;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int max = 0;
        int answer = 0;
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            max = Math.max(max, arr[i]);
        }

        int left = max, right = 100_000 * 100_000;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (M >= getCount(mid, arr)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        bw.write(String.valueOf(answer));
        bw.flush();

    }

    public static int getCount(int amount, int[] arr) {
        int count = 1;
        int money = amount;

        for (int x : arr) {
            money -= x;
            if (money < 0) {
                count++;
                money = amount - x;
            }
        }
        return count;
    }
}
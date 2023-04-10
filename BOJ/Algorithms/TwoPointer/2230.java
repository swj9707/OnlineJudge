package BOJ.Algorithms.TwoPointer;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int N, M;
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int left = 0, right = 0;
        int[] arr = new int[N];
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        while(right < N) {
            if(arr[right] - arr[left] < M) {
                right++;
                continue;
            }

            if(arr[right] - arr[left] == M) {
                ans = M;
                break;
            }

            ans = Math.min(ans, arr[right] - arr[left]);
            left++;
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }
}
package BOJ.Algorithms.Greedy;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int answer = 0;
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];
        Integer[] diff = new Integer[N - 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < N; i++) {
            diff[i - 1] = arr[i] - arr[i - 1];
        }

        Arrays.sort(diff, Collections.reverseOrder());
        answer = Arrays.stream(diff).mapToInt(Integer::valueOf).sum();

        for (int i = 0; i < K - 1; i++) {
            answer -= diff[i];
        }

        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
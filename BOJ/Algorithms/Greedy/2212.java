package BOJ.Algorithms.Greedy;

import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int answer = 0;
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());

        if (K >= N) {
            bw.write("0\n");
            bw.flush();
            return;
        }

        int[] censor = new int[N];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            censor[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(censor);

        int[] diff = new int[N - 1];

        for (int i = 0; i < N - 1; i++) {
            diff[i] = censor[i + 1] - censor[i];
        }
        Arrays.sort(diff);

        for (int i = 0; i < N - K; i++) {
            answer += diff[i];
        }

        bw.write(String.valueOf(answer));
        bw.flush();

    }
}

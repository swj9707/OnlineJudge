package BOJ.Algorithms.Greedy;

import java.io.*;
import java.util.*;

class Main {
    static int[] DP = new int[16];
    static int[] T = new int[16];
    static int[] P = new int[16];
    static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken());
            P[i] = Integer.parseInt(st.nextToken());
            DP[i] = -1;
        }

        int answer = solve(1);
        bw.write(String.valueOf(answer));
        bw.flush();

    }

    public static int solve(int day) {
        if(day > N + 1) {
            return -1000000;
        }
        if(day == N + 1) {
            return 0;
        }

        int ret = DP[day];
        if(ret != -1) return ret;
        ret = Math.max(solve(day + 1), solve(day + T[day]) + P[day]);
        return ret;
    }
}

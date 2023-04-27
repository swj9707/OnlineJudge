package BOJ.Algorithms.Simulation;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int answer = 0;
        int now = 0;

        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int D = Integer.parseInt(st.nextToken());
            int R = Integer.parseInt(st.nextToken());
            int G = Integer.parseInt(st.nextToken());
            answer += D - now;
            now = D;
            if(answer % (R + G) <= R) {
                answer += (R - (answer % (R + G)));
            }
        }
        answer += L - now;

        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
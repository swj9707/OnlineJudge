package BOJ.Algorithms.Greedy;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int answer = 0;
        int easy = 0, hard = 0;
        int[][] ques = new int[N][2];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            ques[i][0] = Integer.parseInt(st.nextToken());
            ques[i][1] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < N; i++){
           if(ques[i][1] <= L){
            hard += 1;
           } else if (ques[i][0] <= L){
            easy += 1;
           }
        }

        answer += Math.min(hard, K) * 140;
        if(hard < K){
            answer += Math.min(easy, K - hard) * 100;
        }

        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
package Softeer.LV2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        long K, P, N;
        StringTokenizer st = new StringTokenizer(br.readLine());
        K = Long.parseLong(st.nextToken());
        P = Long.parseLong(st.nextToken());
        N = Long.parseLong(st.nextToken());

        for(int i = 0; i < N; i++){
            K = K * P % 1000000007;
        }

        bw.write(String.valueOf(K %  1000000007));
        bw.flush();
    }
    
}

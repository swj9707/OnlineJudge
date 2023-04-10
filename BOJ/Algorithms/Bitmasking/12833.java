package BOJ.Algorithms.Bitmasking;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken()) % 2;

        int ans = A;
        if(C == 1) {
            ans = A ^ B;
        }

        bw.write(String.valueOf(ans));
        bw.flush();
    }
}
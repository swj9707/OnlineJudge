package BOJ.Algorithms.BruteForce;

import java.io.*;
import java.util.*;

class Main {

    static boolean[] buttons = {true, true, true, true, true, true, true, true, true, true}; 
    static int N;
    static int M;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        
        
        if(M != 0) {
            st = new StringTokenizer(br.readLine());

            for(int i = 0; i < M; i++) {
                buttons[Integer.parseInt(st.nextToken())] = false;
            }
            
        }

        if(N == 100) {
            bw.write(String.valueOf(0));
            bw.flush();
            return;
        }

        int cnt = Math.abs(100 - N);
        min = min > cnt ? cnt : min;

        dfs(0, "");
        bw.write(String.valueOf(min));
        bw.flush();
        return;

    }

    public static void dfs(int idx, String click) {
        for(int i = 0; i < 10; i++) {
            if(buttons[i]) {
                String newStr = click + Integer.toString(i);
                int cnt = Math.abs(N - Integer.parseInt(newStr)) + newStr.length();
                min = min > cnt ? cnt : min;
                if(idx < 6) {
                    dfs(idx + 1, newStr);
                }
            }
        }
    }
    
}

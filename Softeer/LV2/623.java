package Softeer.LV2;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        
        int K, M, N;
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        
        String pattern = "";
        String userInput = "";
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            pattern += st.nextToken();
        }

        st =  new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            userInput += st.nextToken();
        }

        if(userInput.contains(pattern)){
            bw.write("secret");
        } else {
            bw.write("normal");
        }
        bw.flush();   
    }
}

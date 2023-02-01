package Softeer.LV3;

import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
    
        int N = Integer.parseInt(st.nextToken());
        int result = 0;
        List<Integer> list = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            list.add(Integer.parseInt(st.nextToken()));    
        }

        int[] DP = new int[N];
        for(int i = 0; i < N; i++){
            DP[i] = 1;
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j <= i; j++){
                if(list.get(i) > list.get(j)){
                    DP[i] = Math.max(DP[i], DP[j] + 1);
                }
            }
        }

        for(int i = 0; i < N; i++){
            result = Math.max(result, DP[i]);
        }

        bw.write(String.valueOf(result));
        bw.flush();
       
    }
}

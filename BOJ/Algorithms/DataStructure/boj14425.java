package BOJ.Algorithms.DataStructure;

import java.io.*;
import java.util.*;

public class boj14425 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter( new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int answer = 0;
        int N, M;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> map = new HashMap<>();
        for(int i = 0; i < N; i++){
            String tmp = br.readLine();
            map.put(tmp, 1);
        }
        for(int i = 0; i < M; i++){
            String tmp = br.readLine();
            if(map.containsKey(tmp)){
                answer++;
            }
        }
        bw.write(Integer.toString(answer));
        br.close();
        bw.close();
    }
}

package BOJ.Algorithms.DataStructure;

import java.util.*;
import java.io.*;

public class boj1269 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A, B;
        int answer = 0;
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        HashMap<Integer, Integer> map = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < A; i++){
            int tmp = Integer.parseInt(st.nextToken());
            map.put(tmp, map.getOrDefault(tmp, 0) + 1);
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < B; i++){
            int tmp = Integer.parseInt(st.nextToken());
            map.put(tmp, map.getOrDefault(tmp, 0) + 1);    
        }
        for(int i : map.keySet()){
            if(map.get(i) == 1) answer++;
        }
        bw.write(Integer.toString(answer));
    }
}

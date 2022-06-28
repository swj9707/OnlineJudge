package BOJ.Algorithms.DataStructure;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
public class boj2164 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N;
        N = Integer.parseInt(br.readLine());
        Queue<Integer> que = new LinkedList<>();
        for(int i = 1; i <= N; i++){
            que.add(i);
        }
        while(que.size() != 1){
            que.poll();
            int frontData = que.poll();
            que.add(frontData);
        }
        int answer = que.poll();
        bw.write(Integer.toString(answer));
        br.close();
        bw.close();
    }
}

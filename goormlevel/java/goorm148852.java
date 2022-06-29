package goormlevel.java;

import java.io.*;
import java.util.*;

public class goorm148852 {
    final static int MAX = 10001;
    static int[][] MATRIX = new int[MAX][MAX];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer stk = new StringTokenizer(br.readLine(), " ");
        int N = Integer.parseInt(stk.nextToken());
        int M = Integer.parseInt(stk.nextToken());
        int K = Integer.parseInt(stk.nextToken());

        String data = br.readLine();

        MATRIX[1][1] = 1;
        int x = 1, y = 1;
        int answer = 1;

        for(int i = 0; i < K; i++){
            char cmd = data.charAt(i);
            int nx = x, ny = y;
            if(cmd == 'E'){
                ny = y - 1;
            } else if (cmd == 'W'){
                ny = y + 1;
            } else if (cmd == 'S'){
                nx = x + 1;
            } else if (cmd == 'N'){
                nx = x - 1;
            }
            if(nx > 0 && ny <= N && ny > 0 && ny <= M){
                MATRIX[nx][ny] = MATRIX[nx][ny] + 1;
                x = nx;
                y = ny;
                answer = Math.max(answer, MATRIX[nx][ny]);
            } else {
                MATRIX[x][y] = MATRIX[x][y] + 1;
                answer = Math.max(answer, MATRIX[x][y]);
            }
        }
        bw.write(Integer.toString(answer));
        br.close();
        bw.close();
    } 
}

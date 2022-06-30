package BOJ.Algorithms.BackTracking;

import java.util.*;
import java.io.*;

public class boj15649 {
    final static int MAX = 9;
    static int[] MATRIX = new int[MAX];
    static boolean[] visit = new boolean[MAX];
    public static void main(String[] args){
        int N, M;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        DFS(N, M, 0);
    }

    static void DFS(int N, int M, int count){
        if(count == M){
            for(int i = 0; i < M; i++){
                System.out.print(MATRIX[i] + " ");
            }
            System.out.println();
            return;
        }
        for(int i = 1; i <= N; i++){
            if(!visit[i]){
                visit[i] = true;
                MATRIX[count] = i;
                DFS(N, M, count+1);
                visit[i] = false;
            }
        }
    }
}

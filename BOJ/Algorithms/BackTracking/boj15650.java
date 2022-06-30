package BOJ.Algorithms.BackTracking;

import java.io.*;
import java.util.*;

public class boj15650 {
    static int[] MATRIX = new int[9];
    static boolean[] visit = new boolean[9];

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N, M;
        N = sc.nextInt();
        M = sc.nextInt();
        DFS(N, M, 1, 0);
    }

    static void DFS(int n, int m, int num, int count){
        if(count == m){
            for(int i = 0; i < m; i++){
                System.out.print(MATRIX[i] + " ");
            }
            System.out.println();
            return;
        }
        for(int i = num; i <= n; i++){
            if(!visit[i]){
                visit[i] = true;
                MATRIX[count] = i;
                DFS(n, m, i + 1, count + 1);
                visit[i] = false;
            }
        }
    }
}

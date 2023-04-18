package BOJ.Algorithms.BruteForce;

import java.util.*;
import java.io.*;

class Main {
    static int [][] MATRIX;
    static boolean[] visit;
    static int[] arr;
    static int answer = 9999999;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        MATRIX = new int[N][N];
        visit = new boolean[N];
        arr = new int[N];
        
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                MATRIX[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        DFS(0, N);
        bw.write(String.valueOf(answer));
        bw.flush();
    }

    // public static void initArr(int N) {
    //     for(int i = 0; i < N; i++) {
    //         arr[i] = 0;
    //     }
    // } 

    public static void DFS(int count, int N) {
        if(count == N) {
            for(int i = 0; i < N; i++) {
                
            }
            int startTeamScore = MATRIX[arr[0]][arr[1]] + MATRIX[arr[1]][arr[0]];
            int linkTeamScore = MATRIX[arr[2]][arr[3]] + MATRIX[arr[3]][arr[2]];
            System.out.println(startTeamScore + " " + linkTeamScore);
            answer = Math.min(answer, Math.abs(startTeamScore - linkTeamScore));
        }

        for(int i = 0; i < N; i++) {
            if(!visit[i]) {
                visit[i] = true;
                arr[count] = i;
                DFS(count + 1, N);
                visit[i] = false;
            }
        }

    }
}

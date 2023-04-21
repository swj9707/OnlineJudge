package BOJ.Algorithms.Simulation;

import java.io.*;
import java.util.*;

class Main {

    static char[][] MATRIX = new char[100][100];
    static int[][] result = new int[100][100];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());
        int count = 1;
        Queue<int[]> que = new ArrayDeque<>();
        
        for(int i = 0; i < H; i++) {
            char[] charArr = br.readLine().toCharArray();
            for(int j = 0; j < W; j++) {
                MATRIX[i][j] = charArr[j];
                if(charArr[j] == 'c') {
                    que.add(new int[] {i, j});
                }
            }
        }

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(MATRIX[i][j] != 'c') {
                    result[i][j] = -1;
                } 
            }
        }

        while(true) {
            if(que.isEmpty()) {
                break;
            } else {
                Queue<int[]> bufferQue = new ArrayDeque<>();
                while(!que.isEmpty()) {
                    int[] topElement = que.poll();
                    if(topElement[1] + 1 < W) {
                        topElement[1] += 1;
                        if(result[topElement[0]][topElement[1]] == -1) {
                            result[topElement[0]][topElement[1]] = count;
                        }
                        bufferQue.add(new int[] {topElement[0], topElement[1]});
                    }
                }
                que = bufferQue;
                count++;
            }
        }

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                bw.write(String.valueOf(result[i][j]) + " ");
            }
            bw.write("\n");
        }

        bw.flush();
    }
}
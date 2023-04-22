package BOJ.Algorithms.Simulation;

import java.io.*;
import java.util.*;

class Main {

    static int[][][] MATRIX = new int[200][200][2];
    static int[] dx = {0, 0, 0, 1, -1};
    static int[] dy = {0, 1, -1, 0, 0}; 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        for(int i = 0; i < R; i++) {
            String tmp = br.readLine();
            for(int j = 0; j < C; j++) {
                MATRIX[i][j][0] = tmp.charAt(j);
                if(tmp.charAt(j) == 'O') {
                    MATRIX[i][j][1] = 3;
                }
            }
        }

        for(int second = 1; second <= N; second++) {
            if(second % 2 == 0) {
                for(int i = 0; i < R; i++) {
                    for(int j = 0; j < C; j++) {
                        if(MATRIX[i][j][0] == '.') {
                            MATRIX[i][j][0] = 'O';
                            MATRIX[i][j][1] = second + 3;
                        }
                    }
                }
            } else {
                for(int i = 0; i < R; i++) {
                    for(int j = 0; j < C; j++) {
                        if(MATRIX[i][j][1] == second) {
                            int x = i;
                            int y = j;
                            MATRIX[x][y][0] = '.';
                            MATRIX[x][y][1] = 0;
                            for(int r = 0; r < 5; r++) {
                                int nx = x + dx[r];
                                int ny = y + dy[r];
                                if(nx >= 0 && nx < R && ny >= 0 && ny < C){
                                    if(MATRIX[nx][ny][0] == 'O' && MATRIX[nx][ny][1] != second) {
                                        MATRIX[nx][ny][0] = '.';
                                        MATRIX[nx][ny][1] = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }                
        }

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                bw.write(String.valueOf((char)MATRIX[i][j][0]));
            }
            bw.write("\n");
        }
        bw.flush();

    }
}

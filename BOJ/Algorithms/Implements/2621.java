package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {

    static int[] color = new int[4];
    static int[] digit = new int[10];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        for (int i = 0; i < 5; i++) {
            st = new StringTokenizer(br.readLine());
            char color = st.nextToken().charAt(0);
            int number = Integer.parseInt(st.nextToken());
        }

    }
}
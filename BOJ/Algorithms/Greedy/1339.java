package BOJ.Algorithms.Greedy;

import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int answer = 0;
        int[] alpha = new int[26];

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();

            int size = tmp.length();

            int base = (int) Math.pow(10, size - 1);

            for (int j = 0; j < size; j++) {
                alpha[tmp.charAt(j) - 'A'] += base;
                base /= 10;
            }
        }

        Arrays.sort(alpha);

        for (int i = 25; i >= 17; i--) {
            answer += alpha[i] * (i - 16);
        }
        bw.write(String.valueOf(answer));
        bw.flush();
    }

}

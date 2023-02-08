package Softeer.LV3;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int result = 0;

        char[] dataArr = new char[N];
        st = new StringTokenizer(br.readLine());
        String data = st.nextToken();
        for (int i = 0; i < N; i++) {
            dataArr[i] = data.charAt(i);
        }

        for (int i = 0; i < N; i++) {
            if (dataArr[i] == 'P') {
                for (int j = i - K; j <= i + K; j++) {
                    if (j < 0 || j >= N)
                        continue;
                    if (dataArr[j] == 'H') {
                        dataArr[j] = 'X';
                        result++;
                        break;
                    }
                }
            }
        }

        bw.write(String.valueOf(result));
        bw.flush();
    }
}
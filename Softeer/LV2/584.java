package Softeer.LV2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int N, M;
        int answer = 0;
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        List<Integer> first = new ArrayList<>();
        List<Integer> second = new ArrayList<>();

        for(int i = 0; i < N; i++){
            int a, b;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            for(int j = 0; j < a; j++){
                first.add(b);
            }
        }

        for(int i = 0; i < M; i++){
            int a, b;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            for(int j = 0; j < a; j++){
                second.add(b);
            }
        }

        for(int i = 0; i < 100; i++){
            answer = Math.max(answer, second.get(i) - first.get(i));
        }
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}

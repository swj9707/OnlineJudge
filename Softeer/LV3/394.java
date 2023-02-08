package Softeer.LV3;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] arrOfWeight = new int[N + 1];
        int result = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arrOfWeight[i] = Integer.parseInt(st.nextToken());
        }

        List<Stack<Integer>> listOfStacks = new ArrayList<>();

        for (int i = 0; i <= N; i++) {
            listOfStacks.add(new Stack<Integer>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int U = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            listOfStacks.get(U).add(V);
            listOfStacks.get(V).add(U);
        }

        for (int i = 1; i <= N; i++) {
            while (!listOfStacks.get(i).isEmpty() && arrOfWeight[listOfStacks.get(i).peek()] < arrOfWeight[i]) {
                listOfStacks.get(i).pop();
            }
            if (listOfStacks.get(i).isEmpty()) {
                result++;
            }
        }

        bw.write(String.valueOf(result));
        bw.flush();

    }
}

package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int TestCase = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < TestCase; tc++) {
            int N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            int[] arr = new int[N];
            Map<Integer, Integer> mpFirst = new HashMap<>();
            Map<Integer, List<Integer>> mpSecond = new HashMap<>();

            for (int i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                mpFirst.put(arr[i], mpFirst.getOrDefault(arr[i], 0) + 1);
                if (mpFirst.get(arr[i]).equals(6) && !mpSecond.containsKey(arr[i])) {
                    mpSecond.put(arr[i], new ArrayList<>());
                }
            }

            int score = 1;
            int min = Integer.MAX_VALUE;
            int answer = 0;

            for (int i = 0; i < N; i++) {
                if (mpSecond.containsKey(arr[i])) {
                    mpSecond.get(arr[i]).add(score);
                    score++;
                }
            }

            for (int x : mpSecond.keySet()) {
                int scoreX = 0;
                for (int i = 0; i < 4; i++) {
                    scoreX = mpSecond.get(x).get(i);
                }
                if (min > scoreX) {
                    min = scoreX;
                    answer = x;
                } else if (min == scoreX) {
                    if (mpSecond.get(answer).get(4) > mpSecond.get(x).get(4)) {
                        answer = x;
                    }
                }
            }

            bw.write(String.valueOf(answer) + "\n");
        }

        bw.flush();
    }
}
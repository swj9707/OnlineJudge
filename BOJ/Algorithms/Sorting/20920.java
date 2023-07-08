package BOJ.Algorithms.Sorting;

import java.util.*;
import java.util.stream.Collectors;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Map<String, Integer> mp = new HashMap<String, Integer>();

        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            if (tmp.length() < M) {
                continue;
            }

            mp.put(tmp, mp.getOrDefault(tmp, 0) + 1);
        }

        List<String> wordList = mp.keySet().stream().collect(Collectors.toList());

        wordList.sort((o1, o2) -> {
            int count1 = mp.get(o1);
            int count2 = mp.get(o2);

            if (count1 != count2) {
                return count2 - count1;
            }

            if (o1.length() != o2.length()) {
                return o2.length() - o1.length();
            }

            return o1.compareTo(o2);

        });

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < wordList.size(); i++) {
            sb.append(wordList.get(i)).append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
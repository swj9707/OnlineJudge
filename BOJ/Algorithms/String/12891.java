package BOJ.Algorithms.String;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int S = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        int answer = 0;
        String tmp = br.readLine();

        int start = 0, end = P - 1;
        HashMap<Character, Integer> windowHashMap = new HashMap<>();
        HashMap<Character, Integer> minimumHashMap = new HashMap<>();
        st = new StringTokenizer(br.readLine());

        windowHashMap.put('A', 0);
        windowHashMap.put('C', 0);
        windowHashMap.put('G', 0);
        windowHashMap.put('T', 0);

        minimumHashMap.put('A', Integer.parseInt(st.nextToken()));
        minimumHashMap.put('C', Integer.parseInt(st.nextToken()));
        minimumHashMap.put('G', Integer.parseInt(st.nextToken()));
        minimumHashMap.put('T', Integer.parseInt(st.nextToken()));

        for (int i = start; i <= end; i++) {
            windowHashMap.put(tmp.charAt(i), windowHashMap.getOrDefault(tmp.charAt(i), 0) + 1);
        }

        while (end < S) {
            if (windowHashMap.containsKey('A') && windowHashMap.containsKey('C')
                    && windowHashMap.containsKey('G') && windowHashMap.containsKey('T')) {
                if (windowHashMap.getOrDefault('A', 0) >= minimumHashMap.get('A')
                        && windowHashMap.getOrDefault('C', 0) >= minimumHashMap.get('C') &&
                        windowHashMap.getOrDefault('G', 0) >= minimumHashMap.get('G')
                        && windowHashMap.getOrDefault('T', 0) >= minimumHashMap.get('T')) {
                    answer++;
                }
            }
            end++;
            if (end < S) {
                windowHashMap.put(tmp.charAt(start), windowHashMap.getOrDefault(tmp.charAt(start), 1) - 1);
                windowHashMap.put(tmp.charAt(end), windowHashMap.getOrDefault(tmp.charAt(end), 0) + 1);
                start++;
            }

        }

        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
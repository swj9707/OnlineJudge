package BOJ.Algorithms.DataStructure;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        char G = st.nextToken().toCharArray()[0];
        int answer = 0;
        Set<String> hashSet = new HashSet<>();

        for (int i = 0; i < N; i++) {
            hashSet.add(br.readLine());
        }

        if (G == 'Y') {
            answer = hashSet.size() / 1;
        } else if (G == 'F') {
            answer = hashSet.size() / 2;
        } else if (G == 'O') {
            answer = hashSet.size() / 3;
        }

        bw.write(String.valueOf(answer));
        bw.flush();

    }
}
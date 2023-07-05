package BOJ.Algorithms.DataStructure.Stack;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            Deque<Character> left = new ArrayDeque<>();
            Deque<Character> right = new ArrayDeque<>();
            String tmp = br.readLine();
            for (int i = 0; i < tmp.length(); i++) {
                char tmpChar = tmp.charAt(i);
                if (tmpChar == '<') {
                    if (!left.isEmpty()) {
                        right.push(left.pop());
                    }
                } else if (tmpChar == '>') {
                    if (!right.isEmpty()) {
                        left.push(right.pop());
                    }
                } else if (tmpChar == '-') {
                    if (!left.isEmpty()) {
                        left.pop();
                    }
                } else {
                    left.push(tmpChar);
                }
            }

            while (!left.isEmpty()) {
                right.push(left.pop());
            }

            while (!right.isEmpty()) {
                sb.append(right.pop());
            }
            sb.append("\n");
        }

        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
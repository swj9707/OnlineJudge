package BOJ.Algorithms.Implements;

import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int score = 0;
        Map<Character, Integer> colorMap = new HashMap<>();
        int[] digitArr = new int[10];
        int maxNum = 0;
        for (int i = 0; i < 5; i++) {
            String[] tmpData = br.readLine().split(" ");
            char cardColor = tmpData[0].charAt(0);
            int cardNumber = Integer.parseInt(tmpData[1]);
            colorMap.put(cardColor, colorMap.getOrDefault(cardColor, 0) + 1);
            digitArr[cardNumber]++;
            maxNum = Math.max(maxNum, cardNumber);
        }
        boolean isStraight = false;
        boolean isFlush = false;

        List<Integer> pair = new ArrayList<>();
        int triple = 0;
        int quad = 0;

        if (colorMap.keySet().size() == 1) {
            isFlush = true;
        }

        for (int i = 1; i < 6; i++) {
            if (digitArr[i] == 1 && digitArr[i + 1] == 1 && digitArr[i + 2] == 1 && digitArr[i + 3] == 1
                    && digitArr[i + 4] == 1) {
                isStraight = true;
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (digitArr[i] == 2) {
                pair.add(i);
            } else if (digitArr[i] == 3) {
                triple = i;
            } else if (digitArr[i] == 4) {
                quad = i;
            }
        }

        if (isFlush && isStraight) {
            score = 900 + maxNum;
        } else if (isFlush) {
            score = 600 + maxNum;
        } else if (isStraight) {
            score = 500 + maxNum;
        } else if (quad != 0) {
            score = 800 + quad;
        } else if (triple != 0 && !pair.isEmpty()) {
            score = 700 + 10 * triple * pair.get(0);
        } else if (triple != 0) {
            score = 400 + triple;
        } else if (pair.size() == 2) {
            int pair1 = pair.get(0);
            int pair2 = pair.get(1);
            score = 300 + 10 * Math.max(pair1, pair2) + Math.min(pair1, pair2);
        } else if (pair.size() == 1) {
            score = 200 + pair.get(0);
        } else {
            score = 100 + maxNum;
        }

        bw.write(String.valueOf(score) + '\n');
        bw.flush();
    }
}
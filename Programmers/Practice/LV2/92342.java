package Programmers.Practice.LV2;

class Solution {
    static int max;
    static int[] answer;

    public int[] solution(int n, int[] info) {
        answer = new int[11];
        DFS(0, n, 0, new int[n], info);

        return max == 0 ? new int[] { -1 } : answer;
    }

    public static void DFS(int start, int r, int idx, int[] result, int[] info) {
        if (idx == r) {
            int[] info2 = new int[11];
            for (int score : result) {
                info2[10 - score]++;
            }
            int ryan = 0;
            int apeach = 0;

            for (int i = 0; i < 11; i++) {
                int score = 10 - i;
                if (info2[i] > info[i]) {
                    ryan += score;
                } else if (info2[i] < info[i]) {
                    apeach += score;
                } else if (info[i] != 0 && info2[i] == info[i]) {
                    apeach += score;
                }
            }

            if (ryan - apeach > max) {
                max = ryan - apeach;
                answer = info2;
            }
            return;
        }

        for (int i = start; i < 11; i++) {
            result[idx] = i;
            DFS(i, r, idx + 1, result, info);
        }
    }
}
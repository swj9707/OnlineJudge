package LV2;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int n) {
        int[][] MATRIX = new int[n][n];
        int x = -1;
        int y = 0;
        int num = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i % 3 == 0) {
                    x++;
                } else if (i % 3 == 1) {
                    y++;
                } else if (i % 3 == 2) {
                    x--;
                    y--;
                }
                MATRIX[x][y] = num++;
            }
        }

        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (MATRIX[i][j] != 0) {
                    list.add(MATRIX[i][j]);
                }
            }
        }

        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}
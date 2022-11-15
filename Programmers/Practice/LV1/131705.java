package LV1;

class Solution {

    boolean[] Visit = new boolean[14];
    int[] MATRIX = new int[3];
    int count = 0;

    public int solution(int[] number) {
        DFS(number, 0, 0);
        return count;
    }

    public void DFS(int[] number, int idx, int N) {
        if (N == 3) {
            if (MATRIX[0] + MATRIX[1] + MATRIX[2] == 0) {
                count++;
            }
            return;
        }

        for (int i = idx; i < number.length; i++) {
            if (!Visit[i]) {
                Visit[i] = true;
                MATRIX[N] = number[i];
                DFS(number, i, N + 1);
                Visit[i] = false;
            }
        }
    }
}
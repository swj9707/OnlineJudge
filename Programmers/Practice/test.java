class Solution {

    final int MOD = 1000000007;

    public int solution(int m, int n, int[][] puddles) {

        int[][] MATRIX = new int[n + 1][m + 1];
        for (int i = 0; i < puddles.length; i++) {
            int X = puddles[i][1];
            int Y = puddles[i][0];
            MATRIX[X][Y] = -1;
        }

        MATRIX[1][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (MATRIX[i][j] != -1) {
                    if (MATRIX[i - 1][j] != -1)
                        MATRIX[i][j] += MATRIX[i - 1][j];
                    if (MATRIX[i][j - 1] != -1)
                        MATRIX[i][j] += MATRIX[i][j - 1];
                }
            }
        }

        return MATRIX[n][m] % MOD;
    }
}
package Programmers.PCCP.PCCP_1;

class Solution {

    boolean[] VISIT = new boolean[10];
    int[] MATRIX = new int[10];
    int maxValue = -1;

    public int solution(int[][] ability) {
        DFS(0, ability[0].length, ability.length, ability);
        return maxValue;
    }

    public void DFS(int count, int n, int max, int[][] ability) {
        if(count == n){
            int result = 0;
            for(int i =0; i < n; i++){
                result += ability[MATRIX[i]][i];
            }
            maxValue = Math.max(maxValue, result);
            return;
        }

        for(int i = 0; i < max; i++){
            if(!VISIT[i]){
                VISIT[i] = true;
                MATRIX[count] = i;
                DFS(count+1, n, max, ability);
                VISIT[i] = false;
            }
        }
    }
}
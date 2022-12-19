package Programmers.codingTest_Kit.DFS_BFS;

class Solution {

    public boolean[] VISIT = new boolean[201];

    public void DFS(int n, int[][] computers, int idx){
        VISIT[idx] = true;
        for(int i = 0; i < n; i++){
            if(i != idx && computers[idx][i] == 1){
                if(VISIT[i] == false){
                    DFS(n, computers, i);
                }
            }
        }

    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(VISIT[i] == false){
                DFS(n, computers, i);
                answer++;
            }
        }
        return answer;
    }
}
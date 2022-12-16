package Programmers.codingTest_Kit.DFS_BFS;

class Solution {
    int answer = 0;
    public void dfs(int n, int target, int idx, int result, int[] numbers){
        if(idx == n ){
            if(result == target){
                answer++;
            }
            return;
        } else {
            dfs(n, target, idx + 1, result + numbers[idx], numbers);
            dfs(n, target, idx + 1, result - numbers[idx], numbers);
        }
    }

    public int solution(int[] numbers, int target) {
        
        dfs(numbers.length, target, 0, 0, numbers);
        return answer;
    }
}

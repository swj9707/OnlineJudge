package Programmers.codingTest_Kit.DFS_BFS;

class Solution {

    static final int INF = 98765432;
    static boolean[] VISIT = new boolean[50];
    static int answer = INF;
    
    public int solution(String begin, String target, String[] words) {
        DFS(begin, target, words, 0);
        if(answer == INF) return 0;
        return answer;
    }

    public static int compStr(String A, String B, int N) {
        int result = 0;
        for(int i = 0; i < N; i++) {
            if(A.charAt(i) != B.charAt(i)) {
                result++;
            }
        }
        return result;
    }

    public static void DFS(String data, String target, String[] words, int count) {
        if(data == target) {
            answer = Math.min(answer, count);
            return;
        }

        for(int i = 0; i < words.length; i++) {
            if(compStr(data, words[i], data.length()) == 1) {
                if(!VISIT[i]) {
                    VISIT[i] = true;
                    DFS(words[i], target, words, count + 1);
                    VISIT[i] = false;
                }
            }
        }
    }
}
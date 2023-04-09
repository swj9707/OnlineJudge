package Programmers.Practice.LV1;

import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = players;
        
        Map<String, Integer> scoreBoard = new HashMap<>();
        
        for(int i = 0; i < players.length; i++){
            scoreBoard.put(players[i], i + 1);
        }

        for(String runner : callings) {
            int aIdx = scoreBoard.get(runner);
            int bIdx = aIdx - 1;
            String nextRunner = answer[bIdx];

            answer[aIdx] = nextRunner;
            answer[bIdx] = runner;
            
            scoreBoard.put(nextRunner, aIdx);
            scoreBoard.put(runner, bIdx);
            
        }
        
        
        return answer;
    }
}

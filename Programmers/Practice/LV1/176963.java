package Programmers.Practice.LV1;

import java.util.*;


class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int [photo.length];
        Map<String, Integer> scorMap = new HashMap<>();

        for(int i = 0; i < name.length; i++){
            scorMap.put(name[i], yearning[i]);
        }

        for(int i = 0; i < photo.length; i++){
            int tmp  = 0;
            for(int j =0; j < photo[i].length; j++){
                if(scorMap.containsKey(photo[i][j])){
                    tmp += scorMap.get(photo[i][j]);
                }
            }
            answer[i] = tmp;
        }

        return answer;
    }
}
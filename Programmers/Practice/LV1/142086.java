package LV1;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int [s.length()];

        Map<Character, Integer> mp = new HashMap<>();
        for(int i = 0; i < s.length(); i++){
            char tmp = s.charAt(i);
            if(!mp.containsKey(tmp)){
                answer[i] = -1;
            } else {
                answer[i] = i - mp.get(tmp);
            }
            mp.put(tmp, i);
        }

        return answer;
    }
}

import java.util.*;

class Solution {
    public int solution(String name) {
        int answer = 0;
        for(char x : name.toCharArray()) {
            answer += Math.min((int)(x - 'A'), (int)('Z' + 1 - x));
        }
        int len = name.length();
        int move = len - 1;

        for(int i = 0; i < len; i++) {
            int next = i + 1;
            while(next < len && name.charAt(next) == 'A') next++;
            move = Math.min(move, i + (len - next) + Math.min(i, len - next));
        }
        answer += move;

        return answer;
    }
}
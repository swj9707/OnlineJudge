package Programmers.Practice.LV2;

import java.util.HashSet;
import java.util.Set;

class Solution {
    public int solution(String dirs) {
        int answer = 0;
        Set<String> visitSet = new HashSet<>();

        int x = 0, y = 0;

        for (int i = 0; i < dirs.length(); i++) {
            int reX = x, reY = y;
            char dir = dirs.charAt(i);
            if (dir == 'U' && y < 5) {
                y++;
            } else if (dir == 'D' && y > -5) {
                y--;
            } else if (dir == 'L' && x > -5) {
                x--;
            } else if (dir == 'R' && x < 5) {
                x++;
            }

            String xy = Integer.toString(x) + Integer.toString(y);
            String reXY = Integer.toString(reX) + Integer.toString(reY);
            String st = xy + reXY;
            String nd = reXY + xy;

            if (!st.equals(nd)) {
                visitSet.add(st);
                visitSet.add(nd);
            }
        }

        answer = visitSet.size() / 2;

        return answer;
    }
}
package Programmers.Practice.LV1;

import java.util.*;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        List<Integer> answer = new ArrayList();

        HashMap<Character, Integer> mp = new HashMap<>();

        for (String x : keymap) {
            for (int i = 0; i < x.length(); i++) {
                if (mp.containsKey(x.charAt(i))) {
                    int value = Math.min(mp.get(x.charAt(i)).intValue(), i + 1);
                    mp.put(x.charAt(i), value);
                } else {
                    mp.put(x.charAt(i), i + 1);
                }
            }
        }

        for (int i = 0; i < targets.length; i++) {
            int result = 0;
            for (int j = 0; j < targets[i].length(); j++) {
                char tmp = targets[i].charAt(j);
                if (mp.containsKey(tmp)) {
                    result += mp.get(tmp);
                } else {
                    result = -1;
                    break;
                }
            }
            answer.add(result);
        }

        return answer.stream().mapToInt(Integer::valueOf).toArray();
    }
}
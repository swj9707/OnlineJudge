package Programmers.Practice.LV2;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;

        Map<String, Integer> myMap = new HashMap<>();
        Map<String, Integer> dataMap = new HashMap<>();
        for (int i = 0; i < want.length; i++) {
            myMap.put(want[i], number[i]);
        }

        for (int i = 0; i < 10; i++) {
            dataMap.put(discount[i], dataMap.getOrDefault(discount[i], 0) + 1);
        }

        if (isEqual(myMap, dataMap)) {
            answer++;
        }

        for (int i = 1; i <= discount.length - 10; i++) {
            String yesterday = discount[i - 1];
            dataMap.put(yesterday, dataMap.get(yesterday) - 1);
            String tomorrow = discount[i - 1 + 10];
            dataMap.put(tomorrow, dataMap.getOrDefault(tomorrow, 0) + 1);
            if (isEqual(myMap, dataMap)) {
                answer++;
            }
        }

        return answer;
    }

    public boolean isEqual(Map<String, Integer> a, Map<String, Integer> b) {
        for (String key : a.keySet()) {
            if (!b.containsKey(key) || a.get(key) != b.get(key)) {
                return false;
            }
        }
        return true;
    }
}
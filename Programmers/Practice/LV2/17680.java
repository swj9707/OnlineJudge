package Programmers.Practice.LV2;

import java.util.LinkedList;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;

        if (cacheSize == 0) {
            return cities.length * 5;
        }

        LinkedList<String> cache = new LinkedList<>();

        for (String data : cities) {
            String tmp = data.toUpperCase();
            if (cache.remove(tmp)) {
                answer += 1;
                cache.add(tmp);
            } else {
                answer += 5;
                if (cache.size() >= cacheSize) {
                    cache.remove(0);
                }
                cache.add(tmp);
            }
        }

        return answer;
    }
}
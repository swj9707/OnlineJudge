package Programmers.Practice.LV1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {

    public int getDays(String date){
        String[] data = date.split("\\.");
        return Integer.parseInt(data[0]) * 12 * 28 + Integer.parseInt(data[1]) * 28 + Integer.parseInt(data[2]);
    }

    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> result = new ArrayList<>();
        
        int today_days = getDays(today);
        
        HashMap<String, Integer> map = new HashMap<>(); 
        for(String x : terms){
            String[] data = x.split(" ");
            map.put(data[0], Integer.parseInt(data[1]) * 28);
        }

        for(int i = 0; i < privacies.length; i++){
            String[] tmpData = privacies[i].split(" ");
            int amountOfDate = getDays(tmpData[0]);
            int gapofDays = map.get(tmpData[1]);
            if(today_days - amountOfDate > gapofDays){
                result.add(i+1);
            }

        }
        
        return result.stream().mapToInt(Integer::valueOf).toArray();
    }
}
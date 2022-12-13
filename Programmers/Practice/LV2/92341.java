package LV2;

import java.util.TreeMap;

class Solution {

    public int timeToInt(String time){
        String data[] = time.split(":");
        return Integer.parseInt(data[0]) * 60 + Integer.parseInt(data[1]);
    }

    public int[] solution(int[] fees, String[] records) {
      
        TreeMap<String, Integer> map = new TreeMap<>();

        for(String record : records){
            String tmp[] = record.split(" ");
            int time = tmp[2].equals("IN") ? -1  : 1;
            time *= timeToInt(tmp[0]);
            map.put(tmp[1], map.getOrDefault(tmp[1], 0) + time);
        }

        int index = 0;
        int[] answer = new int[map.size()];
        for(int time : map.values()){
            if(time < 1) time += 1439;
            time -= fees[0];
            int cost = fees[1];
            if(time > 0){
                cost += (time % fees[2] == 0 ? time/fees[2] : time/fees[2] + 1) * fees[3];
            }
            answer[index++] = cost;
        }
       return answer;
    }
}
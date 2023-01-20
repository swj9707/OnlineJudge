package Programmers.Practice.LV2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    public int[] solution(String msg) {
        List<Integer> answer = new ArrayList<>();
        HashMap<String, Integer> dic = new HashMap<>();

        for(int i = 1; i <= 26; i++ ){
            char tmp =  (char)('A' + i - 1);
            dic.put(tmp + "", i);
        }
        System.out.println(dic.toString());

        int next = 27;

        for(int i = 0; i < msg.length(); i++){
            int idx = 1;

            while(i + idx <= msg.length() && dic.containsKey(msg.substring(i, i + idx))){
                idx++;
            }

            if(i + idx > msg.length()){
                answer.add(dic.get(msg.substring(i)));
                break;
            }

            answer.add(dic.get(msg.substring(i, i + idx - 1)));
            dic.put(msg.substring(i, i + idx - 1), next++);
            if(idx > 1) i += idx - 2;
        }
       
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
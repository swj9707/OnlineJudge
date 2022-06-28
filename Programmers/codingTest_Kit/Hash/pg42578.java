package Programmers.codingTest_Kit.Hash;

import java.util.*;

public class pg42578 {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<>();
    
        for(var i : clothes){
            String type = i[1];
            map.put(type, map.getOrDefault(type, 0) + 1);
        }

        Iterator<Integer> it = map.values().iterator();

        while(it.hasNext()){
            answer *= it.next().intValue() + 1;
        }

        return answer - 1;
    }
}

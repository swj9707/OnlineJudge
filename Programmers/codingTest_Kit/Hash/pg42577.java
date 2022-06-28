package Programmers.codingTest_Kit.Hash;

import java.util.HashMap;

public class pg42577 {
    public boolean solution(String[] phone_book){
        boolean answer = true;
        HashMap<String, Integer> map = new HashMap<>();
        String str = "";
        for(String i : phone_book){
            str = "";
            for(int j = 0; j < i.length(); j++){
                str += i.charAt(j);
                map.put(str, map.getOrDefault(str, 0) + 1);
            }
        }
        for(String i : phone_book){
            if(map.get(i) > 1){
                answer = false;
                break;
            }
        }

        return answer;
    }
}

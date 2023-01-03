package Programmers.PCCP.PCCP_1;

import java.util.HashMap;

class Solution {
    public String solution(String input_string) {
        String answer = "";
        HashMap<Character, Integer> countExpose = new HashMap<>();
        HashMap<Character, Integer> countDivide = new HashMap<>();
        char prevChar = '-';
        for(int i = 0; i < input_string.length(); i++){
            char tmp = input_string.charAt(i);
            countExpose.put(tmp, countExpose.getOrDefault(tmp, 0) + 1);
            if(prevChar != tmp){
                countDivide.put(tmp, countDivide.getOrDefault(tmp, 0) + 1);
                prevChar = tmp;
            }
        }

        for(char a : countExpose.keySet()){
            if(countDivide.get(a) >= 2 && countExpose.get(a) >= 2){
                answer += a;
            }
        }
        if(answer == ""){
            answer = "N";
        }

        return answer;
    }
}
package Programmers.Practice.LV2;

import java.util.*;

class Solution {
    public int solution(int[] order) {        
        int count = 0;

        Stack<Integer> conv = new Stack<>();
        Queue<Integer> que = new LinkedList<>();

        for(int i = 0; i < order.length; i++){
            conv.add(i + 1);

            while(!conv.isEmpty()){
                if(conv.peek() == order[count]){
                    que.offer(conv.pop());
                    count++;
                } else break;
            }
        }


        return que.size();
    }
}
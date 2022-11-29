package LV2;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Solution {
    public int solution(int[] order) {
        int answer = 0;

        Queue<Integer> belt = new LinkedList<>();
        Stack<Integer> subBelt = new Stack<>();

        for(int i = 0; i < order.length; i++){
            belt.offer(i + 1);
        } 

        int selected = 0;

        for(int i : order){
            while(true){
                if(!belt.isEmpty()){
                    if(belt.peek() == i){
                        selected = belt.peek();
                        belt.poll();
                        answer++;
                    } else {
                        subBelt.push(belt.poll());
                    }
                }

                if(i < selected){
                    if(subBelt.peek() == i){
                        selected = subBelt.peek();
                        subBelt.pop();
                        answer++;
                        break;
                    } else {
                        return answer;
                    }
                }
            }
        }

        return answer;
    }
}
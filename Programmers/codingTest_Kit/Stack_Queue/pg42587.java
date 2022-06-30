package Programmers.codingTest_Kit.Stack_Queue;

import java.util.*;

public class pg42587 {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        PriorityQueue<Integer> PQ = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0; i < priorities.length; i++){
            PQ.add(priorities[i]);
        }

        while(!PQ.isEmpty()){
            for(int i = 0; i < priorities.length; i++){
                if(priorities[i] == PQ.peek()){
                    if(i == location){
                        answer++;
                        return answer;
                    }
                    PQ.poll();
                    answer++;
                }
            }
        }

        return -1;
    }
}

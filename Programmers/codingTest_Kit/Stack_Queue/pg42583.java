package Programmers.codingTest_Kit.Stack_Queue;

import java.util.*;

public class pg42583 {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int idx = 0, sum = 0;
        Queue<Integer> Q = new LinkedList<>();

        while(true){
            if(idx == truck_weights.length){
                answer += bridge_length;
                break;
            }
            answer++;
            int tmp = truck_weights[idx];
            if(Q.size() == bridge_length){
                sum -= Q.peek();
                Q.poll();
            }
            if(sum + tmp <= weight){
                Q.add(tmp);
                sum += tmp;
                idx++;
            }
            else{
                Q.add(0);
            }
        }
        return answer;
    }
    
}

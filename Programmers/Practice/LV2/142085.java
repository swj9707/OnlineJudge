package LV2;

import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int solution(int n, int k, int[] enemy) {
        int answer = enemy.length;
        
        PriorityQueue<Integer> PQ = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i = 0; i < enemy.length; i++){
            int now = enemy[i];
            n -= now;
            PQ.add(now);

            if(n < 0){
                if( k > 0 && !PQ.isEmpty()){
                    int greater = PQ.poll();
                    n += greater;
                    k--;
                } else {
                    answer = i;
                    break;
                }
            }
        }
        return answer;
    }
}
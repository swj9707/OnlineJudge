package LV3;

import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> PQ = new PriorityQueue<>(Comparator.reverseOrder());
        for(int i = 0; i < works.length; i++){
            PQ.add(works[i]);
        }
        for(int i = 0; i < n; i++){
            if(PQ.isEmpty()){
                break;
            } else {
                int work = PQ.poll();
                if(work - 1 != 0){
                    PQ.add(work - 1);
                }
            }
        }
        for(int x : PQ){
            answer += x * x;
        }
        return answer;
    }
}
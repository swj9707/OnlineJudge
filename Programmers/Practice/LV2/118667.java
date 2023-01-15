package Programmers.Practice.LV2;

import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int solution(int[] queue1, int[] queue2) {

        Queue<Integer> que1 = new LinkedList<>();
        Queue<Integer> que2 = new LinkedList<>();

        long sum1 = 0, sum2 = 0;

        for(int i = 0; i < queue1.length; i++){
            sum1 += queue1[i];
            que1.add(queue1[i]);
        }

        for(int i = 0; i < queue2.length; i++){
            sum2 += queue2[i];
            que2.add(queue2[i]);
        }

        int count = 0; 
        while(sum1 != sum2){
            count++;

            if(sum1 > sum2){
                int tmp = que1.poll();
                sum1 -= tmp;
                sum2 += tmp;
                que2.offer(tmp);
            } else {
                int tmp = que2.poll();
                sum2 -= tmp;
                sum1 += tmp;
                que1.offer(tmp);
            }
            if(count > (queue1.length + queue2.length) * 2) return -1;
        }

        return count;
    }
}
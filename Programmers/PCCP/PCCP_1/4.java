package Programmers.PCCP.PCCP_1;

import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.stream.Collectors;

class Solution {
    public long[] solution(int[][] program) {
        long[] answer = new long[11];
        Arrays.sort(program, (o1, o2) -> o1[1] - o2[1]);
        Queue<int[]> que = (Queue<int[]>) Arrays.stream(program).collect(Collectors.toList());

        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            if(o1[0] == o2[0]){
                return o1[1] - o2[1];
            }
            return o1[0] - o2[0];
        });
        int time = 0;
        int execute = 0;
        
        while(execute < program.length){
            if(pq.isEmpty()){
                while(pq.peek()[])
            }    
        }
        
        return answer;
    }
} 
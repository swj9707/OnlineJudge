package Programmers.codingTest_Kit.Stack_Queue;

import java.util.*;

public class pg42586 {
    class Solution {
        public int[] solution(int[] progresses, int[] speeds) {
           
            Queue<Integer> queue = new LinkedList<>();
            List<Integer> answerList = new ArrayList<>();

            for(int i = 0; i < progresses.length; i++){
                int leftRate = 100 - progresses[i];
                int date = leftRate / speeds[i];
                if(leftRate % speeds[i] != 0) date += 1;
                queue.offer(date);
            }
            int start = queue.peek();
            int count = 0;

            while(!queue.isEmpty()){
                if(queue.peek() <= start){
                    queue.remove();
                    count++;
                } else {
                    if(count > 0){
                        start = queue.peek();
                        answerList.add(count);
                        count = 0;
                    }
                }
            }
            answerList.add(count);

            int[] answer = new int[answerList.size()];

            for(int i = 0; i < answerList.size(); i++){
                answer[i] = answerList.get(i);
            }

            return answer;
        }
    }
}

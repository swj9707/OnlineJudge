package Programmers.Practice.LV2;

import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int sum = 0;
        int count = 0;
        Queue<Integer> bridgeQue = new ArrayDeque<>();
        Queue<Integer> startQue = new ArrayDeque<>();
        Queue<Integer> endQue = new ArrayDeque<>();

        for (int i = 0; i < truck_weights.length; i++) {
            startQue.add(truck_weights[i]);
        }

        for (int i = 0; i < bridge_length; i++) {
            bridgeQue.add(0);
        }

        while (endQue.size() != truck_weights.length) {
            answer++;
            if (bridgeQue.size() == bridge_length) {
                if (bridgeQue.peek() != 0) {
                    endQue.add(bridgeQue.peek());
                }
                sum -= bridgeQue.poll();
            }

            if (!startQue.isEmpty() && startQue.peek() + sum <= weight) {
                bridgeQue.add(startQue.peek());
                sum += startQue.poll();
            } else {
                bridgeQue.add(0);
            }

        }

        return answer;
    }
}
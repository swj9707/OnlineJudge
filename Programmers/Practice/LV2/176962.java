package Programmers.Practice.LV2;

import java.util.*;

class Task {
    String title;
    int startTime;
    int playTime;

    public Task(String title, int startTime, int playTime) {
        this.title = title;
        this.startTime = startTime;
        this.playTime = playTime;
    }
}

class Solution {

    public int getTime(String time) {
        return Integer.parseInt(time.substring(0, 2)) * 60 + Integer.parseInt(time.substring(3, 5));
    }

    public String[] solution(String[][] plans) {
        List<String> answer = new ArrayList<>();
        Arrays.sort(plans, (o1, o2) -> (o1[1].compareTo(o2[1])));
        Deque<Task> dq = new ArrayDeque<>();

        for (String[] plan : plans) {
            int start = getTime(plan[1]);
            int playTime = getTime(plan[2]);

            if (!dq.isEmpty()) {
                Task now = dq.pop();
                if (now.startTime + now.playTime > start) {
                    dq.push(new Task(now.title, start, now.playTime - (start - now.startTime)));
                } else {
                    answer.add(now.title);
                    int remain = start - (now.startTime + now.playTime);
                    while (remain > 0 && !dq.isEmpty()) {
                        int removeTask = dq.peek().playTime - remain;
                        dq.peek().playTime = Math.max(0, removeTask);
                        if (removeTask <= 0) {
                            remain = -1 * removeTask;
                            answer.add(dq.pop().title);
                        } else {
                            remain = 0;
                        }
                    }
                }
            }
            dq.push(new Task(plan[0], start, playTime));
        }

        while (!dq.isEmpty()) {
            answer.add(dq.pop().title);
        }

        return answer.toArray(new String[answer.size()]);
    }
}
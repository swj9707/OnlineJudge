import java.util.*;

class pg42862 {
public int[] solution(int[] array, int[][] commands) {
        int[] answer = {};
        answer = new int[commands.length];
        for(int i = 0; i < commands.length; i++){
            int start = commands[i][0], end = commands[i][1], k = commands[i][2];
            List<Integer> list = new ArrayList<>();
            for(int idx = start - 1; idx <= end - 1; idx++){
                list.add(array[idx]);
            }
            Collections.sort(list);
            answer[i] = list.get(k-1);
        }
        return answer;
    }
}
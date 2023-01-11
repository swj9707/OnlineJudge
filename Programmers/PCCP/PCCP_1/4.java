import java.util.*;
class Solution {
    public long[] solution(int[][] program) {
        long[] answer = new long[11];
        int proLen = program.length;
        Arrays.sort(program, (o1, o2) -> o1[1] - o2[1]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            if(o1[0] == o2[0]) {
                return o1[1] - o2[1];
            }
            return o1[0] - o2[0];
        });
        
        int cnt = 0;
        int lastComp = 0;
        int idx = 0;
        int time = 0;
        while(cnt < proLen) {
            
            for(int i = idx; i < proLen; i++) {
                int sc = program[i][0];
                int ti = program[i][1];
                int ex = program[i][2];
                int arr[] = {sc, ti, ex};
                if(ti <= time) {
                    pq.add(arr);
                    idx++;
                } else {
                    break;
                }
            }
            
            if(!pq.isEmpty() && lastComp <= time) {
                int ar[] = pq.poll();
                int sc = ar[0];
                int ti = ar[1];
                int ex = ar[2];
                
                lastComp = time + ex;
                answer[sc] += time - ti;
                cnt++;
            }
                      
            time++;
        }
        answer[0] = lastComp;    
        
        return answer;
    }
    
}

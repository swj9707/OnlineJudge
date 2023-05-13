import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;

        Arrays.sort(routes, (a, b) -> a[0] - b[0]);

        int camera = -98765432;
        
        for(int i = 0; i < routes.length; i++) {
            if(camera < routes[i][0]) {
                answer++;
                camera = routes[i][1];
            }

            if(camera >= routes[i][1]) {
                camera = routes[i][1];
            }
        }


        return answer;
    }
}
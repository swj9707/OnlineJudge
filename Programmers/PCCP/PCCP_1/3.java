import java.util.ArrayList;
import java.util.List;

class Solution {
    
    int[] cong = {0,0,1,1,2};

    public String[] solution(int[][] queries) {
        List<String> answer = new ArrayList<>();

        for(int i = 0; i < queries.length; i++){
            int a = queries[i][0];
            int b = queries[i][1];

            if(a == 1) {
                answer.add("Rr");
                continue;
            }

            int n = dfs(a, b);
            if(n == 0){
                answer.add("RR");
            } else if (n == 2){
                answer.add("rr");
            } else {
                answer.add("Rr");
            }

        }
        
        return answer.toArray(new String[answer.size()]);
    }

    public int dfs(int a, int b){
        if( a== 2){
            return cong[b];
        }

        int x = b / 4;
        int y = b % 4;
        if(y != 0) {
            x++;
        }
        int n = dfs(a - 1, x);
        if( n == 0) { 
            return 0;
        } else if (n == 2) {
            return 0;
        }
        else {
            if(y == 1) {
                return 0;
            }
            else if (y == 0) { 
                return 2;
            }
            else {
                return 1;
            }
        }
    }
}
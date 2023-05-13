import java.util.*;

class Solution {

    static final int MAX = 101;
    static int[] Parent = new int[MAX]; 

    public int solution(int n, int[][] costs) {
        int answer = 0;
        
        Arrays.sort(costs, (int[] a, int[] b) -> a[2] - b[2]);

        for(int i = 0; i < n; i++) {
            Parent[i] = i;
        }

        for(int[] edge : costs) {
            int from = edge[0];
            int to = edge[1];
            int cost = edge[2];
            
            if(findParent(from, to)) continue;
            answer += cost;
            unionParent(from, to);
        }

        return answer;
    }

    public static int getParent(int num) {
        if (num == Parent[num]) return num;
        return Parent[num] = getParent(Parent[num]);
    }

    public static void unionParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a != b) Parent[a] = b;
    }

    public static boolean findParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if (a == b) return true;
        else return false;
    }
}
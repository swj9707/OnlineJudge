package Programmers.Practice.LV1;

import java.util.*;

public class pg42862 {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n;
        HashSet<Integer> resList = new HashSet<>();
        HashSet<Integer> losList = new HashSet<>();

        for (int i : reserve)
            resList.add(i);
        for (int i : lost) {
            if(resList.contains(i))
                resList.remove(i);
            else
                losList.add(i);
        }
        for (int i : lost) {
            if(losList.contains(i)) {
                if(resList.contains(i-1))
                    resList.remove(i-1);
                else if(resList.contains(i+1))
                    resList.remove(i+1);
                else
                    answer--;
            }
        } 
        return answer;
    }
}

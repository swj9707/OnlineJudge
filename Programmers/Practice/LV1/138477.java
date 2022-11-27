import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Solution {
    public int[] solution(int k, int[] score) {
        int[] answer = new int[score.length];
        List<Integer> tmpList = new ArrayList<>();
        for(int i = 0; i < score.length; i++){
            int tmp = score[i];
            if(tmpList.size() >= k){
                if(tmpList.get(tmpList.size() - 1) < tmp){
                    tmpList.remove(tmpList.size() - 1);
                    tmpList.add(tmp);
                }
            } else {
                tmpList.add(tmp);
            }
            tmpList.sort(Comparator.reverseOrder());
            answer[i] = tmpList.get(tmpList.size() - 1);

        }
        return answer;
    }
}
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int solution(int[][] dots) {
        List<Double> leanArr = new ArrayList<>();
        for (int i = 0; i < dots.length; i++) {
            for (int j = i + 1; j < dots.length; j++) {
                Double curLean = (double) ((dots[i][1] - dots[j][1]) / (dots[i][0] - dots[i][1]));
                if (leanArr.isEmpty()) {
                    leanArr.add(curLean);
                } else {
                    if (!leanArr.contains(curLean)) {
                        leanArr.add(curLean);
                    } else {
                        return 1;
                    }
                }

            }
        }
        return 0;
    }
}
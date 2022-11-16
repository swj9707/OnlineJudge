package LV2;

import java.util.*;

class Solution {
    public int[] solution(long begin, long end) {
        List<Integer> board = new ArrayList<>();

        for (long i = begin; i <= end; i++) {
            if (i == 1) {
                board.add(0);
                continue;
            } else {
                board.add((int) block(i));
            }
        }

        return board.stream().mapToInt(Integer::intValue).toArray();
    }

    public long block(long n) {
        for (long i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i > 10000000) {
                    continue;
                }
                return n / i;
            }
        }
        return 1;
    }
}
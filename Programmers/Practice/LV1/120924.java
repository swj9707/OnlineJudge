class Solution {
    public int solution(int[] common) {
        int answer = 0;
        boolean check = true;
        int length = common.length;
        int diff = 0;
        if (common[1] - common[0] == common[2] - common[1]) {
            check = true;
            diff = common[1] - common[0];
        } else {
            check = false;
            diff = common[1] / common[0];
        }

        if (check) {
            answer = common[length - 1] + diff;
        } else {
            answer = common[length - 1] * diff;
        }

        return answer;
    }
}
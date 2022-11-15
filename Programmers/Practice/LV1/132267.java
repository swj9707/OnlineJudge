package LV1;

class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;

        while (true) {
            if (n < a)
                break;
            int bottle = n / a;
            int mod = n % a;
            answer += bottle;
            n = bottle + mod;
        }

        return answer;
    }
}

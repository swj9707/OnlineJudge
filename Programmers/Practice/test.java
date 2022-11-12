class Solution {
    public int solution(int chicken) {
        int answer = 0;
        while (chicken >= 10) {
            int div = chicken / 10;
            int mod = chicken % 10;
            answer += div;
            chicken = div + mod;
        }
        return answer;
    }
}
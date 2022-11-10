class Solution {
    public int solution(String A, String B) {
        int answer = -1;
        int len = A.length();

        for (int i = 1; i < len; i++) {

            char first = A.charAt(len - 1);
            A = first + A.substring(1, len - 2);
            if (A.equals(B)) {
                answer = i;
                break;
            }
        }

        return answer;
    }
}
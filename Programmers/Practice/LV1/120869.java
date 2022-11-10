class Solution {
    public int solution(String[] spell, String[] dic) {
        int answer = 2;

        for (String string : dic) {
            int score = 0;
            for (String data : spell) {
                if (string.contains(data)) {
                    score++;
                }
            }
            if (score == spell.length) {
                answer = 1;
                break;
            }
        }

        return answer;
    }
}
package Programmers.Practice.LV2;

class Solution {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;

        for (String skilltree : skill_trees) {
            String tmp = skilltree;
            for (int i = 0; i < skilltree.length(); i++) {
                String s = skilltree.substring(i, i + 1);
                if (!skill.contains(s)) {
                    tmp = tmp.replace(s, "");
                }
            }

            if (skill.indexOf(tmp) == 0) {
                answer++;
            }
        }

        return answer;
    }
}
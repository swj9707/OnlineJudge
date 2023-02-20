package Programmers.Practice.LV1;

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        int card1Idx = 0;
        int card2Idx = 0;
        int card1Length = cards1.length;
        int card2Length = cards2.length;

        for (int i = 0; i < goal.length; i++) {
            String curStr = goal[i];
            if (card1Idx < card1Length && curStr.equals(cards1[card1Idx])) {
                card1Idx++;
            } else if (card2Idx < card2Length && curStr.equals(cards2[card2Idx])) {
                card2Idx++;
            } else {
                return "No";
            }
        }

        return "Yes";
    }
}
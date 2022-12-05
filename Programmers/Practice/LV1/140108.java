package LV1;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int count1 = 0, count2 = 0;
        char tmp = s.charAt(0);

        for(int i = 0; i < s.length(); i++){
            if(count1 == count2){
                answer++;
                tmp = s.charAt(i);
            }
            if(tmp == s.charAt(i)){
                count1++;
            } else {
                count2++;
            }
        }

        return answer;
    }
}
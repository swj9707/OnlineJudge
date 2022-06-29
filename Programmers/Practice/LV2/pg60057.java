package Programmers.Practice.LV2;

public class pg60057 {
    public int solution(String s) {
        int answer = s.length();
        for(int i = 1; i <= s.length() / 2; i++){
            String tmp = "";
            String substr = s.substring(0, i);
            int count = 1;
            for(int j = i; j < s.length(); j+=i){
                if(substr.equals(s.substring(j, j + i))) count++;
                else{
                    if(count > 1) tmp += Integer.toString(count);
                    tmp += substr;
                    substr = s.substring(j, j + i);
                    count = 1;
                }
            }
            if(count > 1) tmp += Integer.toString(count);
            tmp += substr;
            if(answer > tmp.length()) answer = tmp.length();
        }

        return answer;
    }
}

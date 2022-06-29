package Programmers.Practice.LV1;

public class pg81301 {

    boolean isNum(char c){
        return '0' <= c && c <= '9';
    }

    public int solution(String s) {
        int answer = 0;

        String str = "";
        for(int i = 0; i < s.length(); i++){
            if(isNum(s.charAt(i))){
                str += s.charAt(i);
                continue;
            }
            
            if(s.length() - i >= 5 && s.substring(i, i + 5).equals("three")) str += '3';
            else if (s.length() - i >= 5 && s.substring(i, i + 5).equals("seven")) str += '7';
            else if (s.length() - i >= 5 && s.substring(i, i + 5).equals("eight")) str += '8';
            else if (s.length() - i >= 4 && s.substring(i, i + 4).equals("zero")) str += '0';
            else if (s.length() - i >= 4 && s.substring(i, i + 4).equals("four")) str += '4';
            else if (s.length() - i >= 4 && s.substring(i, i + 4).equals("five")) str += '5';
            else if (s.length() - i >= 4 && s.substring(i, i + 4).equals("nine")) str += '9';
            else if (s.length() - i >= 3 && s.substring(i, i + 3).equals("one")) str += '1';
            else if (s.length() - i >= 3 && s.substring(i, i + 3).equals("two")) str += '2';
            else if (s.length() - i >= 3 && s.substring(i, i + 3).equals("six")) str += '6';
        }

        answer = Integer.parseInt(str);

        return answer;
    }
}

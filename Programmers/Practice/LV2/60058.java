package Programmers.Practice.LV2;

import java.util.Stack;

class Solution {
    public String solution(String p) {
        String answer = dfs(p);
        return answer;
    }

    public String dfs(String w){
      if(w.equals("")){
        return "";
      }

      String u = "";
      String v = "";

      int lCount = 0;
      int rCount = 0;

      for(int i = 0; i < w.length(); i++){
        if(w.charAt(i) == '('){
            lCount++;
        } else {
            rCount++;
        }
        u += w.charAt(i);
        if(lCount == rCount){
            v = w.substring(i + 1);
            break;
        }
      }

      if(isCorrect(u)){
        return u + dfs(v);
      } else {
        String tmp = "(";

        tmp += dfs(v);
        tmp += ")";

        u = u.substring(1, u.length() - 1);

        for(int i = 0; i < u.length(); i++){
            if(u.charAt(i) == '('){
                tmp += ')';
            } else {
                tmp += '(';
            }
        }
        return tmp;
      }
    }

    public boolean isCorrect(String param){
       Stack<Character> stk = new Stack<>();

       for(int i = 0; i < param.length(); i++){
        if(param.charAt(i) == '('){
            stk.push('(');
        } else {
            if(stk.isEmpty() || stk.peek() == ')'){
                return false;
            } else {
                stk.pop();
            }
        }
    }

        return true;
    }
}

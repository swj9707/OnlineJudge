package LV2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int solution(String str1, String str2) {

        List<String> A = new ArrayList<>();
        List<String> B = new ArrayList<>();
        List<String> union = new ArrayList<>();
        List<String> intersection = new ArrayList<>();

        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        for(int i = 0; i < str1.length() - 1; i++){
            char first = str1.charAt(i);
            char second = str1.charAt(i+1);
            if(first >= 'a' && first <= 'z' &&
                second >= 'a' && second <= 'z'){
                A.add(first + "" + second);
            }
        }

        for(int i = 0; i < str2.length() - 1; i++){
            char first = str2.charAt(i);
            char second = str2.charAt(i+1);
            if(first >= 'a' && first <= 'z' &&
                second >= 'a' && second <= 'z'){
                B.add(first + "" + second);
            }
        }

        Collections.sort(A);
        Collections.sort(B);

        for(String s : A){
            if(B.remove(s)){
              intersection.add(s);
            }
            union.add(s);
        }
        
        for(String s : B){
            union.add(s);
        }
        
        double jakard = 0;
        
        if(union.size() == 0) {
            jakard = 1;
        } else {
            jakard = (double)intersection.size() / (double)union.size();
        }
              
        return (int)(jakard * 65536);
    }
}

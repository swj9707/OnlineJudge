package LV2;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;

        Set<Integer> st = new HashSet<>();
        Map<Integer, Integer> mp = new HashMap<>();

        st.add(topping[0]);
        for(int i = 1; i < topping.length; i++){
            mp.put(topping[i], mp.getOrDefault(topping[i], 0) + 1);
        }

        for(int i = 1; i < topping.length; i++){
            int tmp = topping[i];
            st.add(tmp);
            int numofTopping = mp.get(tmp);
            if(numofTopping == 1){
                mp.remove(tmp);
            }  else {
                mp.put(tmp, numofTopping - 1);
            }

            if(st.size() == mp.size()){
                answer++;
            }
        }

        return answer;
    }
}
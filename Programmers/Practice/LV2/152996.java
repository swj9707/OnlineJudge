package Programmers.Practice.LV2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        Map<Integer, List<Integer>> mp  = new HashMap<>();
        Set<Integer> st = new HashSet<>();

        for(int i = 0; i < weights.length; i++){
            mp.getOrDefault(weights[i], new ArrayList<Integer>()).add(i);
            st.add(weights[i]);
        }

        for(int key: st){
            int dupli = mp.get(key).size();
            int wX2 = key * 2;
            if(wX2 % 3 == 0) {
                if(mp.containsKey(wX2 / 3)){
                    answer += (long)mp.get(wX2/3).size() * dupli;
                }
            }
            
            if(wX2 % 4 == 0) {
                if(mp.containsKey(wX2 /4)){
                    answer += (long)mp.get(wX2/ 4).size() * dupli;
                }
            }
            
            int wX3 = key * 3;
            if(wX3 % 2 == 0) {
                if(mp.containsKey(wX3 / 2)){
                    answer += (long)mp.get(wX3/2).size() * dupli;
                }
            }
            
            if(wX3 % 4 == 0) {
                if(mp.containsKey(wX3 /4)){
                    answer += (long)mp.get(wX3/ 4).size() * dupli;
                }
            }
            
            int wX4 = key * 4;
            if(wX4 % 2 == 0) {
                if(mp.containsKey(wX4 / 2)){
                    answer += (long)mp.get(wX4/2).size() * dupli;
                }
            }
            
            if(wX4 % 3 == 0) {
                if(mp.containsKey(wX4 /3)){
                    answer += (long)mp.get(wX4/ 3).size() * dupli;
                }
            }
            
            if(dupli > 1){
                answer += (long)dupli * (long)(dupli - 1) / 2;
            }
            
            mp.remove(key);
        }

       
        return answer;
    }

    public int gdc(int a, int b) {
		if(a < b){
			int temp = a;
			a = b;
			b = temp;
		}
		while(b != 0) {
			int r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
}
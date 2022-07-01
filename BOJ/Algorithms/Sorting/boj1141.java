package BOJ.Algorithms.Sorting;

import java.util.*;
import java.io.*;

public class boj1141 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());
        int answer = 0;

        String[] strs = new String[N];
        boolean[] check = new boolean[N];
        Arrays.fill(check, true);

        for(int i = 0; i < N; i++){
            strs[i] = br.readLine();
        }
        Arrays.sort(strs, new Comparator<String>() {
			public int compare(String s1, String s2) {
				return Integer.compare(s2.length(), s1.length());
			}
		});

        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(strs[j].substring(0, strs[i].length()).equals(strs[i])){
                    check[i] = false;
                    break;
                }
            }
        }

        for(var i : check){
            if(i) answer++;
        }
        bw.write(Integer.toString(answer));
        br.close();
        bw.close();
    } 
    
}

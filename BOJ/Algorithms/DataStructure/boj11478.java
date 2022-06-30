package BOJ.Algorithms.DataStructure;

import java.util.*;
import java.io.*;

public class boj11478 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String tmp = br.readLine();
        HashSet<String> set = new HashSet<>();
        for(int i = 0; i < tmp.length(); i++){
            String input = "";
            for(int j = i; j < tmp.length(); j++){
                input += tmp.charAt(j);
                set.add(input);
            }
        }
        int answer = set.size();
        bw.write(Integer.toString(answer));
        br.close();
        bw.close();
    }
}

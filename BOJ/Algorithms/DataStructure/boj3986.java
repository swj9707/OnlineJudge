package BOJ.Algorithms.DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj3986 {
    public static void main(String args[]) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());;

        int N = Integer.valueOf(st.nextToken());
        int answer = 0;
        for(int count = 0; count < N; count++){
            String data = br.readLine();
            int len = data.length();
            char[] stack = new char[len];
            int stackIndex = 0;
            for(int i = 0; i < len; i++){
                char tmp = data.charAt(i);
                if(stackIndex == 0 || stack[stackIndex-1] != tmp){
                    stack[stackIndex] = tmp;
                    stackIndex++;
                } else if (stack[stackIndex-1] == tmp){
                    stackIndex--;
                }
            }
            if(stackIndex == 0) answer++;
        }
        System.out.println(answer);
    }
}

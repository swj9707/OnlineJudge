package BOJ.Algorithms.DataStructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj11899 {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String s = in.readLine();
		Stack<Character> stack = new Stack<>();
		int answer = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if(c == '(') {
				stack.add(c);
			}else {
				if(stack.empty()) {
					answer++;
				}else {
					stack.pop();
				}
			}
		}
		answer += stack.size();
		System.out.println(answer);
    }
}

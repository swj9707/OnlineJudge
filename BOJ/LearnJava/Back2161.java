package BOJ.LearnJava;

import java.util.*;

public class Back2161 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Queue<Integer> que = new LinkedList<>();

        for(int i = 1; i <= N; i++) que.add(i);
        while(que.size() > 1){
            int front = que.poll();
            System.out.print(front + " ");
            front = que.poll();
            que.add(front);
        }
        System.out.println(que.poll());
    }
}

package BOJ.Algorithms.Graph.DFS_BFS.BFS;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int F = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());
        int G = Integer.parseInt(st.nextToken());
        int U = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        
        int answer = -1;
        Queue<int[]> que = new ArrayDeque<>();
        boolean[] visit = new boolean[1000001];
        que.add(new int[] {S, 0});
        while(!que.isEmpty()) {
            int now = que.peek()[0];
            int count = que.peek()[1];
            que.poll();
            if(now == G) {
                answer = count;
                break;
            } 
            
            if (now - D > 0 && !visit[now - D]) {
                que.add(new int[] {now - D, count + 1});
                visit[now - D] = true;
            } 
            
            if (now + U <= F && !visit[now + U]) {
                que.add(new int[] {now + U, count + 1});
                visit[now + U] = true;
            }

        }

        if(answer == -1) {
            bw.write("use the stairs\n");
        } else {
            bw.write(String.valueOf(answer));
        }

        bw.flush();
    }
}
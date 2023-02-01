package BOJ.Algorithms.Graph;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N, M, R;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        List<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i = 0; i <= N; i++){
            graph.add(new ArrayList<>());
        }
        int[] result = new int[N + 1];
        boolean[] visit = new boolean[N + 1];
        
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int U = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());
            graph.get(U).add(V);
            graph.get(V).add(U);
        }

        BFS(R, result, visit, graph, 1);

        for(int i = 1; i <= N; i++){
            bw.write(result[i] + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }

    public static void BFS(int X, int[] result, boolean[] visit, List<ArrayList<Integer>> graph, int count){
        Queue<Integer> queue = new LinkedList<>();
        result[X] = count++;
        visit[X] = true;
        queue.add(X);

        while(!queue.isEmpty()){
            int point = queue.poll();
            Collections.sort(graph.get(point), Collections.reverseOrder());

            for(int next : graph.get(point)) {	
    			if(!visit[next]) {	
    				visit[next] = true;	
    				result[next] = count++;	
    				queue.add(next);
    			}
    		}
        }

        return;
    }
}

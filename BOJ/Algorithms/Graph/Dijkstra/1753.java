package BOJ.Algorithms.Graph.Dijkstra;

import java.io.*;
import java.util.*;

class Edge implements Comparable<Edge> {
    int i, v;

    public Edge(int i, int v) {
        this.i = i;
        this.v = v;
    }

    @Override
    public int compareTo(Edge o) {
        return this.v - o.v;
    }
}

class Main {
    final static int INF = 98765432;
    static ArrayList<Edge>[] graph;
    static int Dist[];
    static int V;
    static int E;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        graph = new ArrayList[V + 1];
        Dist = new int[V + 1];

        Arrays.fill(Dist, INF);

        for (int i = 1; i <= V; i++) {
            graph[i] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            graph[start].add(new Edge(end, weight));
        }

        StringBuilder sb = new StringBuilder();
        Dijkstra(K);
        for (int i = 1; i <= V; i++) {
            if (Dist[i] == INF)
                sb.append("INF\n");
            else
                sb.append(Dist[i] + "\n");
        }
        bw.write(sb.toString());
        bw.flush();
    }

    public static void Dijkstra(int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] VISIT = new boolean[V + 1];
        pq.add(new Edge(start, 0));
        Dist[start] = 0;

        while (!pq.isEmpty()) {
            Edge curEdge = pq.poll();
            int cur = curEdge.i;

            if (!VISIT[cur]) {
                VISIT[cur] = true;

                for (Edge edge : graph[cur]) {
                    if (Dist[edge.i] > Dist[cur] + edge.v) {
                        Dist[edge.i] = Dist[cur] + edge.v;
                        pq.add(new Edge(edge.i, Dist[edge.i]));
                    }
                }
            }
        }
    }
}

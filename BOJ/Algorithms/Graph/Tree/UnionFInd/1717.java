package BOJ.Algorithms.Graph.Tree.UnionFInd;

import java.util.*;
import java.io.*;

class Main {
    final static int MAXVALUE = 1000001;
    static int[] parents = new int[MAXVALUE];

    public static void setupParents() {
        for (int i = 0; i < MAXVALUE; i++) {
            parents[i] = i;
        }
    }

    public static int getParent(int a) {
        if (parents[a] == a) {
            return a;
        }
        return parents[a] = getParent(parents[a]);
    }

    public static boolean findUnion(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if (a == b)
            return true;
        else
            return false;
    }

    public static void unionParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if (a != b)
            parents[a] = b;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        setupParents();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int oper = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if (oper == 0) {
                unionParent(a, b);
            } else {
                if (findUnion(a, b)) {
                    bw.write("YES\n");
                } else {
                    bw.write("NO\n");
                }
            }
        }
        bw.flush();
    }
}

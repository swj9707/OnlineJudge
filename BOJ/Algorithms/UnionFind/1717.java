package BOJ.Algorithms.UnionFind;

import java.util.*;
import java.io.*;

class Main {

    static int N;
    static int M;
    static int[] Parent = new int[1000001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= N; i++){
            Parent[i] = i;
        }

        for(int i = 0; i < M; i++) {
            int num, a, b;
            st = new StringTokenizer(br.readLine());
            num = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            if(num == 0) {
                unionParent(a, b);
            } else if (num == 1) {
                if(findParent(a, b)) {
                    bw.write("YES\n");
                } else {
                    bw.write("NO\n");
                }
            }
        }
        bw.flush();

    }

    public static int getParent(int num) {
        if(num == Parent[num]) return num;
        return Parent[num] = getParent(Parent[num]);
    }

    public static void unionParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a != b) Parent[a] = b;
    }

    public static boolean findParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a == b) return true;
        else return false;
    }
    
}

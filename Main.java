import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                int tmp = Integer.parseInt(st.nextToken());
                pq.add(tmp);
            }
        }

        for(int i = 0; i < N - 1; i++){
            pq.poll();
        }
        bw.write(pq.poll());
        br.close();
        bw.close();
    }
}

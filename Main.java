import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            if(a == 0){
                if(pq.isEmpty()){
                    bw.write("-1\n");
                } else {
                    bw.write(Integer.toString(pq.poll()));
                    bw.newLine();
                }
            } else {
                for(int j = 0; j < a; j++){
                    int tmpInt = Integer.parseInt(st.nextToken());
                    pq.add(tmpInt);
                }
            }
        }
        bw.flush();
        br.close();
        bw.close();
    }
}

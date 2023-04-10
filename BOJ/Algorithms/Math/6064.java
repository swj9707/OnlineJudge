package BOJ.Algorithms.Math;

import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());

        while(T-- != 0) {
            st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            int N = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

           int year = x;
           int last = LCM(N,M);
           
           while(true) {
               if(year > last) {
                bw.write(String.valueOf("-1\n"));
                   break;
               }
               else if(((year % N) == 0 ? N : year % N) == y){
                bw.write(String.valueOf(year) + "\n");
                   break;
               }
               year += M;                        
           }
        }
        bw.flush();

    }

    public static int LCM(int A, int B) {
        
        return A * B / GCD(A,B);
    }
    
    public static int GCD(int A, int B) {
        int temp = 0;
        while(B > 0) {
            temp = A % B;
            A = B;
            B = temp;
        }
        return A;
    }
}

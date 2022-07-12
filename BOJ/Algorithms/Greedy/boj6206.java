import java.util.ArrayList;
import java.util.Scanner;

import java.util.*;
import java.io.*;

public class boj6206 {
    static int N;
    static int M;

    public static int cutCake(int data){
        int result = 0;
        while(data > 10){
            if(M > 0){
                if(data - 10 > 0){
                    data -= 10;
                    result++;
                    M--;
                }
            } else break;
        }
        if(data == 10) result++;
        return result;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int answer = 0;
        List<Integer> dataTen = new ArrayList<>();
        List<Integer> dataOther = new ArrayList<>();
        st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < N; i++){
            int data = Integer.parseInt(st.nextToken());
            if(data % 10 == 0) dataTen.add(data);
            else dataOther.add(data);
        }

        Collections.sort(dataTen);
        Collections.sort(dataOther);

        for(var i : dataTen){
            if(M != 0){
                if(i > 10){
                    answer += cutCake(i);
                } else if (i == 10){
                    answer += 1;
                }
            } else break;
        }

        for(var i : dataOther){
            if(M != 0){
                if( i > 10){
                    answer += cutCake(i);
                }
            } else break;
        }

        bw.write(Integer.toString(answer));

        br.close();
        bw.close();
    }
}

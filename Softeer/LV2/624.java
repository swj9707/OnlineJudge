package Softeer.LV2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {

    static int[][] sevenSegment = new int[][] {
        { 1, 1, 1, 1, 1, 1, 0 },
        { 0, 1, 1, 0, 0, 0, 0 },
        { 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 0, 0, 1 },
        { 0, 1, 1, 0, 0, 1, 1 },
        { 1, 0, 1, 1, 0, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 1, 0 },
        { 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1 },
    };

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int T;
        st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());

        for(int tc = 0; tc < T; tc++){
            int A, B;
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());

            int[] arrA = new int[5];
            int[] arrB = new int[5];

            Arrays.fill(arrA, -1);
            Arrays.fill(arrB, -1);

            for(int i = 0; i < 5; i++){
                arrA[i] = A % 10;
                A /= 10;
                if(A == 0) break;
            }

            for(int i = 0; i < 5; i++){
                arrB[i] = B % 10;
                B /= 10;
                if(B == 0) break;
            }

            int result = 0;

            for(int i = 0; i < 5; i++){
                if(arrA[i] != arrB[i]){
                    if(arrA[i] == -1){
                        result += sum(arrB[i]);
                    } else if (arrB[i] == -1){
                        result += sum(arrA[i]);
                    } else {
                        result += diff(arrA[i], arrB[i]);
                    }
                }
            }

            bw.write(String.valueOf(result));
            bw.newLine();
        }
        bw.flush();
    }

    public static int diff(int a, int b){
        int[] arrA = sevenSegment[a];
        int[] arrB = sevenSegment[b];

        int count = 0;
        for(int i = 0; i < 7; i++){
            if(arrA[i] != arrB[i]){
                count++;
            }
        }

        return count;
    }

    public static int sum(int a){
        int[] arr = sevenSegment[a];

        int sum = 0;

        for(int i = 0; i < 7; i++){
            sum += arr[i];
        }

        return sum;
    }
}

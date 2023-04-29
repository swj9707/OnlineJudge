package BOJ.Algorithms.TwoPointer;

import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine()); 
        int answer = 1;
        int[] arr = new int[N + 1];
        for(int i = 0; i <= N; i++) {
            arr[i] = i;
        }

        for(int i = 1; i <= N; i++) {
            arr[i] += arr[i - 1];
        }

        int start = 0, end = 0;
        int sum = arr[end];
        while(end <= N - 1) {
            if(sum == N) {
                answer++;
                end++;
                sum = arr[end] - arr[start];
            } else if (sum < N) {
                end++;
                sum = arr[end] - arr[start];
            } else if (sum > N){
                start++;
                sum = arr[end] - arr[start];
            }
        }
        bw.write(String.valueOf(answer));
        bw.flush();
    }
}
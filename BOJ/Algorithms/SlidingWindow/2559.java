import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int answer = 0;

        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0, right = left + K;
        int sum = 0;

        for (int i = 0; i < right; i++) {
            sum += arr[i];
        }

        answer = sum;

        while (right < N) {
            sum += arr[right];
            sum -= arr[left];
            answer = Math.max(answer, sum);
            left++;
            right++;
        }

        bw.write(String.valueOf(answer));
        bw.flush();

    }
}
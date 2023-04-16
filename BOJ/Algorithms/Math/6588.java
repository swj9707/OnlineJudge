package BOJ.Algorithms.Math;

import java.io.*;

class Main {

    final static int MAXVALUE = 1000001;
    static int[] arr = new int[MAXVALUE];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        setupPrime();

        while (true) {
            int N = Integer.parseInt(br.readLine());
            if (N == 0) {
                break;
            }

            boolean check = false;

            for (int i = 1; i <= N / 2; i++) {
                int A = i;
                int B = N - i;

                if (arr[A] == 0 && arr[B] == 0) {
                    if (A % 2 == 1 && B % 2 == 1) {
                        bw.write(String.valueOf(N) + " = " + String.valueOf(A) +
                                " + " + String.valueOf(B) + "\n");
                        check = true;
                        break;
                    }
                }
            }
            if (!check) {
                bw.write("Goldbanch's conjecture is wrong.\n");
            }
        }
        bw.flush();

    }

    public static void setupPrime() {
        arr[0] = 1;
        arr[1] = 1;

        for (int i = 2; i <= MAXVALUE / 2; i++) {
            if (arr[i] == 0) {
                for (int j = i * 2; j < MAXVALUE; j += i) {
                    arr[j] = 1;
                }
            }
        }
    }
}
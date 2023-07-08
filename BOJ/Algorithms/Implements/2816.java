package BOJ.Algorithms.Implements;

import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String[] arr = new String[N];

        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine();
        }

        for (int i = 0; i < N; i++) {
            if (arr[i].equals("KBS1")) {
                String tmp = "";
                for (int j = i; j > 0; j--) {
                    bw.write(String.valueOf("4"));
                    tmp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = tmp;
                }
                break;
            } else {
                bw.write(String.valueOf("1"));
            }
        }

        if (!arr[1].equals("KBS2")) {
            for (int i = 0; i < N; i++) {
                if (arr[i].equals("KBS2")) {
                    String tmp = "";
                    for (int j = i; j > 1; j--) {
                        bw.write(String.valueOf("4"));
                        tmp = arr[j - 1];
                        arr[j - 1] = arr[j];
                        arr[j] = tmp;
                    }
                    break;
                } else {
                    bw.write(String.valueOf("1"));
                }
            }
        }

        bw.flush();
    }
}
package Softeer.LV3;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        for (int tc = 0; tc < T; tc++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());

            Integer arr[] = new Integer[N];

            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(arr, Collections.reverseOrder());

            TreeMap<Integer, Integer> bin_rem = new TreeMap<>();
            for (int i = 0; i < N; i++) {
                if (bin_rem.ceilingKey(arr[i]) != null && bin_rem.get(bin_rem.ceilingKey(arr[i])) > 0) {

                    int leftcnt = bin_rem.get(bin_rem.ceilingKey(arr[i])) - 1;
                    int key = bin_rem.ceilingKey(arr[i]);
                    if (leftcnt == 0)
                        bin_rem.remove(key);
                    else
                        bin_rem.put(key, bin_rem.get(key) - 1);

                    bin_rem.put(key - arr[i], bin_rem.getOrDefault(key - arr[i], 0) + 1);

                } else {
                    bin_rem.put(900 - arr[i], bin_rem.getOrDefault(900 - arr[i], 0) + 1);
                }

            }
            int ans = 0;

            for (int s : bin_rem.values()) {
                ans += s;
            }

            bw.write(String.valueOf(ans) + "\n");
        }
        bw.flush();
    }
}
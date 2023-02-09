package BOJ.Algorithms.Greedy;

import java.util.*;
import java.util.stream.Collectors;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        List<Integer> crane = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).boxed().collect(Collectors.toList());
        int m = Integer.parseInt(br.readLine());

        List<Integer> box = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt).boxed().collect(Collectors.toList());

        crane.sort(Comparator.reverseOrder());
        box.sort(Comparator.reverseOrder());
        int sec = 0;
        if (box.get(0) > crane.get(0)) {
            bw.write("-1");
            bw.flush();
            return;
        }
        while (!box.isEmpty()) {
            sec++;
            for (Integer curCrane : crane) {
                for (int i = 0; i < box.size(); i++) {
                    if (curCrane >= box.get(i)) {
                        box.remove(i);
                        break;
                    }
                }
            }
        }
        bw.write(String.valueOf(sec));
        bw.flush();
    }
}
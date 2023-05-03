package BOJ.Algorithms.String;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            String tmp = br.readLine();
            if (tmp.equals("end")) {
                break;
            } else {
                if (checkOne(tmp) && checkTwo(tmp) && checkThree(tmp)) {
                    bw.write("<" + tmp + "> is acceptable.\n");
                } else {
                    bw.write("<" + tmp + "> is not acceptable.\n");
                }
            }
        }
        bw.flush();
    }

    public static boolean checkOne(String tmp) {
        for (char x : tmp.toCharArray()) {
            if (List.of('a', 'e', 'i', 'o', 'u').contains(x)) {
                return true;
            }
        }
        return false;
    }

    public static boolean checkTwo(String tmp) {

        boolean[] arr = new boolean[tmp.length()];
        for (int i = 0; i < tmp.length(); i++) {
            if (List.of('a', 'e', 'i', 'o', 'u').contains(tmp.charAt(i))) {
                arr[i] = true;
            } else {
                arr[i] = false;
            }
        }

        boolean checkData = arr[0];
        int count = 1;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] == checkData) {
                count++;
                if (count == 3) {
                    return false;
                }
            } else {
                checkData = arr[i];
                count = 1;
            }
        }

        return true;
    }

    public static boolean checkThree(String tmp) {
        char check = tmp.charAt(0);
        for (int i = 1; i < tmp.length(); i++) {
            if (check == tmp.charAt(i)) {
                if (!(check == 'e' || check == 'o')) {
                    return false;
                }
            }
            check = tmp.charAt(i);
        }
        return true;
    }
}
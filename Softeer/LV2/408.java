package Softeer.LV2;

import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String ascendingData = "12345678";
        String descendingData = "87654321";
        String tmp = "";

        for (int i = 0; i < 8; i++) {
            tmp += st.nextToken();
        }

        if (ascendingData.equals(tmp)) {
            bw.write("ascending");
        } else if (descendingData.equals(tmp)) {
            bw.write("descending");
        } else {
            bw.write("mixed");
        }
        bw.flush();
    }
}

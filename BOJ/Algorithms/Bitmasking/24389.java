package BOJ.Algorithms.Bitmasking;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        

        int A = Integer.parseInt(br.readLine());

        int result = ~A + 1;
        int sameBit = A ^ result;
        int count = 0;
        for(char ch : Integer.toBinaryString(sameBit).toCharArray()) {
            if(ch == '1') {
                count++;
            }
        }

        bw.write(String.valueOf(count));
        bw.flush();

    }
}
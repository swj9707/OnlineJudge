package Softeer.LV1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int answer = 0;
        for(int i = 0; i < 5; i++){
            st = new StringTokenizer(br.readLine());
            String startTimeData = st.nextToken();
            String endTimeData = st.nextToken();
            int startHour = Integer.parseInt(startTimeData.split(":")[0]);
            int startMinute = Integer.parseInt(startTimeData.split(":")[1]);
            int endHour = Integer.parseInt(endTimeData.split(":")[0]);
            int endMinute = Integer.parseInt(endTimeData.split(":")[1]);
            answer += (endHour - startHour) * 60 + (endMinute - startMinute);
        }

        bw.write(String.valueOf(answer));
        bw.flush();
    }
}

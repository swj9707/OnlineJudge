import java.io.*;
import java.util.StringTokenizer;
class goorm149359 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int t = Integer.parseInt(br.readLine());
		String str = br.readLine();
		StringTokenizer st = new StringTokenizer(str);
		int grm = 0, frd = 0;
		for(int i = 0; i < t; i++){
			int countOf = Integer.parseInt(st.nextToken());
			int count = 0;
			if(countOf > 3){
				count += (countOf / 3) + (countOf % 3);
			} else {
				count += countOf;
			}
			if(count % 2 == 0) frd++;
			else grm++;
		}
		if(frd == grm) bw.write("tie\n");
		else {
			String winner = Integer.toString(Math.max(grm, frd));
			bw.write(winner + "\n");
		}
		br.close();
		bw.close();
	}
}
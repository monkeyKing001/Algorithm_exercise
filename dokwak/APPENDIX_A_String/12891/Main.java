import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int [] use = new int[4];//A C G T
		int [] curUse = new int[4];
		int sol = 0;
		String str = br.readLine();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < 4; i++) {
			int num = Integer.parseInt(st.nextToken());
			use[i] = num;
		}
		for (int i = 0; i < str.length(); i++) {
			char next = str.charAt(i);
			if (next == 'A'){
				curUse[0]++;
			}
			else if (next == 'C'){
				curUse[1]++;
			}
			else if (next == 'G'){
				curUse[2]++;
			}
			else if (next == 'T'){
				curUse[3]++;
			}
			//prev minus
			if (i - m >= 0) {
				char prev = str.charAt(i - m);
				if (prev == 'A'){
					curUse[0]--;
				}
				else if (prev == 'C'){
					curUse[1]--;
				}
				else if (prev == 'G'){
					curUse[2]--;
				}
				else if (prev == 'T'){
					curUse[3]--;
				}
			}
			for (int check = 0; check < 4; check++) {
				if (i < m - 1 || use[check] > curUse[check]){
					break;
				}
				if (check == 3){
					sol++;
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



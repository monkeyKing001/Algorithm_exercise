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
		String base = br.readLine();
		int [] baseInfo = new int[26];
		for (int i = 0; i < base.length(); i++) {
			char chr = base.charAt(i);
			int idx = chr - 'A';
			baseInfo[idx]++;
		}
		int sol = 0;
		for (int i = 0; i < n - 1; i++) {
			String input = br.readLine();
			int [] inputInfo = new int[26];
			int [] statisticInfo = new int[26];
			for (int j = 0; j < input.length(); j++) {
				char chr = input.charAt(j);
				int idx = chr - 'A';
				inputInfo[idx]++;
			}
			for (int j = 0; j < 26; j++) {
				statisticInfo[j] = Math.abs(baseInfo[j] - inputInfo[j]);
			}
			int diffSum = 0;
			for (int j = 0; j < 26; j++) {
				if (statisticInfo[j] >= 2 
						||
						(diffSum += statisticInfo[j]) > 2
						||
						(input.length() != base.length() && diffSum >= 2)
						)
					break;
				if (j == 25) {
					sol++;
//					System.out.println("input : " + input);
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



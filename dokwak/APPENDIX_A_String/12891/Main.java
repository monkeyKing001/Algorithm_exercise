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
		int [] need = new int[4];//A C G T
		int [] curUse = new int[4];//A C G T
		int sol = 0;
		String strDNA = br.readLine();
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < 4; i++) {
			int needChar = Integer.parseInt(st.nextToken());
			need[i] = needChar;
		}
//		for (int i = 0; i < 4; i++) {
//			System.out.print(need[i] + " ");
//		}
//		System.out.println();
		for (int i = 0; i < strDNA.length(); i++) {
			char curChar = strDNA.charAt(i);
			if (curChar == 'A')
				curUse[0]++;
			if (curChar == 'C')
				curUse[1]++;
			if (curChar == 'G')
				curUse[2]++;
			if (curChar == 'T')
				curUse[3]++;
			if (i >= m){
				char lastChar = strDNA.charAt(i - m);
				if (lastChar == 'A')
					curUse[0]--;
				if (lastChar == 'C')
					curUse[1]--;
				if (lastChar == 'G')
					curUse[2]--;
				if (lastChar == 'T')
					curUse[3]--;
			}
			for (int charIdx = 0; charIdx < 4 && i >= m - 1; charIdx++) {
				if (need[charIdx] > curUse[charIdx])
					break;
				if (charIdx == 3){
					sol++;
//					System.out.println(strDNA.substring(Integer.max(i - m + 1, 0), i + 1));
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

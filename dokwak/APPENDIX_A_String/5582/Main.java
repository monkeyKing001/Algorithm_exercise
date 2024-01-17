import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input
		String str1 = br.readLine();
		String str2 = br.readLine();
		int n = str1.length();
		int m = str2.length();
		int [][]dp = new int[n + 1][m + 1];
		int sol = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				if (str1.charAt(i) == str2.charAt(j)){
					dp[i + 1][j + 1] = dp[i][j] + 1;
					sol = Integer.max(dp[i + 1][j + 1], sol);
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



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
		String input_str1 = br.readLine();
		String input_str2 = br.readLine();
		char [] str1 = input_str1.toCharArray();
		char [] str2 = input_str2.toCharArray();
		int [][] dp = new int[input_str1.length() + 1][input_str2.length() + 1];
		//init
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				dp[i][j] = 0;
			}
		}
		int sol = -1;
		for (int s1_i = 0; s1_i < str1.length; s1_i++) {
			for (int s2_i = 0; s2_i < str2.length; s2_i++) {
				if (str1[s1_i] == str2[s2_i])
					dp[s1_i + 1][s2_i + 1] = dp[s1_i][s2_i] + 1;
				//different with LCS
//				else{
//					dp[s1_i + 1][s2_i + 1] = Integer.max(dp[s1_i][s2_i + 1], dp[s1_i + 1][s2_i]);
//				}
				if (sol < dp[s1_i + 1][s2_i + 1])
					sol = dp[s1_i + 1][s2_i + 1];
			}
		}
		//print dp
//		for (int s1_i = 0; s1_i < str1.length + 1; s1_i++) {
//			for (int s2_i = 0; s2_i < str2.length + 1; s2_i++) {
//				System.out.print(dp[s1_i][s2_i]);
//			}
//			System.out.println();
//		}
		System.out.println(sol);
		return ;
	}
}



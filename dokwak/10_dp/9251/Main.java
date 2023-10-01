import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dp[][];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		String input1 = br.readLine();
		String input2 = br.readLine();
		dp = new int [1001][1001];
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < input1.length(); i++) {
			for (int j = 0; j < input2.length(); j++) {
				if (input1.charAt(i) == input2.charAt(j))
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else 
					dp[i + 1][j + 1] = Integer.max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
//		for (int i = 1; i < input1.length() + 1; i++) {
//			for (int j = 1; j < input2.length() + 1; j++) {
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		System.out.println(dp[input1.length()][input2.length()]);
		return ;
	}
}

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
		int dp[][] = new int[str1.length() + 1][str2.length() + 1];
		for (int i = 0; i < str1.length(); i++) {
			for (int j = 0; j < str2.length() ; j++){
				if (str1.charAt(i) == str2.charAt(j))
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = Math.max(dp[i][j  +1], dp[i + 1][j]);
			}
//			System.out.println(Arrays.toString(dp[i + 1]));
		}
		int i = str1.length();
		int j = str2.length();
		while (i >= 1 && j >= 1 && dp[i][j] != 0){
			if (str1.charAt(i - 1) == str2.charAt(j - 1)){
				sb.append(str1.charAt(i - 1));
				i--;
				j--;
			}
			else{
				if (i - 1 >= 1 && dp[i - 1][j] == dp[i][j]){
					i--;
				}
				else if (j - 1 >= 1 && dp[i][j - 1] == dp[i][j]){
					j--;
				}
			}
		}
		String LCS = sb.reverse().toString();
		System.out.println(dp[str1.length()][str2.length()]);
		System.out.println(LCS);
		bw.flush();
		return ;
	}
}

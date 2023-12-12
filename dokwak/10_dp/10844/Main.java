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
		int mod = 1000000000;
		int dp [][] = new int[101][10];
		for (int i = 1; i < 10; i++) {
			dp[1][i] = 1;
		}
		for (int i = 2; i < 101; i++) {
			for (int j = 0; j < 10; j++) {
				if (j == 0)
					dp[i][j] += dp[i - 1][1] % mod;
				if (j == 9)
					dp[i][j] += dp[i - 1][8] % mod;
				if (j != 0 && j != 9){
					dp[i][j] += dp[i - 1][j - 1] % mod;
					dp[i][j] += dp[i - 1][j + 1] % mod;
				}
				dp[i][j] %= mod;
			}
		}
		int sol = 0;
		for (int i = 0; i < 10; i++) {
			sol += (dp[n][i] % mod); 
			sol %= mod;
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



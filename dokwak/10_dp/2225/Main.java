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
		int mod = 1000000000;
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int dp[][] = new int[201][201];
		for (int i = 0; i < 201; i++) {
			for (int j = 0; j < 201 ; j++){
				dp[i][j] = 0;
				if (i == 1)
					dp[i][j] = 1;
			}
		}
		for (int i = 2; i < 201; i++) {
			for (int j = 0; j < 201 ; j++){
				for (int k = 0; k <= j; k++) {
					dp[i][j] += dp[i - 1][k] % mod;
					dp[i][j] %= mod;
				}
			}
		}
//		for (int i = 0; i <= m; i++) {
//			for (int j = 0; j <= n ; j++){
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		sb.append(dp[m][n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		long [][] arr = new long[n][n];
		long [][] dp = new long[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j <= i; j++) {
				long num = Long.parseLong(st.nextToken());
				arr[i][j] = num;
			}
		}
		dp[0][0] = arr[0][0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0)
					dp[i][j] = dp[i - 1][0] + arr[i][j];
				else if (j == i)
				{
					dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
				}
				else
				{
					dp[i][j] = Long.max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
				}
			}
		}
		long sol = 0;
		for (int i = 0; i < n; i++) {
			if (sol < dp[n - 1][i])
				sol = dp[n-1][i];
		}
		System.out.println(sol);
		return ;
	}
}



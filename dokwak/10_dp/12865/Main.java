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
		int maxWeight = m;
		int dp[][] = new int[n + 1][maxWeight + 1];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int w = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			for (int j = 0; j < w && j <= maxWeight; j++) {
				dp[i + 1][j] = dp[i][j];
			}
			for (int j = w; j <= maxWeight; j++) {
				dp[i + 1][j] = Math.max(dp[i][j], dp[i][j - w] + v);
			}
		}
//		for (int i = 0; i <= n; i++) {
//			for (int j = 0; j <= maxWeight; j++){
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		int sol = dp[n][maxWeight];
		System.out.println(sol);
		return ;
	}
}

import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int T;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		T = Integer.parseInt(st.nextToken());
		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			int [][] arr = new int[2][n + 1];
			int [][] dp = new int[2][n + 1];
			//input;
			for (int i = 0; i < 2; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				for (int j = 0; j < n; j++) {
					int num = Integer.parseInt(st.nextToken());
					arr[i][j] = num;
				}
			}
//			for (int i = 0; i < 2; i++) {
//				for (int j = 0; j < n; j++) {
//					System.out.print(arr[i][j] + " ");
//				}
//				System.out.print("\n");
//			}
			dp[0][0] = arr[0][0];
			dp[1][0] = arr[1][0];
			dp[0][1] = dp[1][0] + arr[0][1];
			dp[1][1] = dp[0][0] + arr[1][1];
			for (int i = 2; i < n; i++) {
				dp[0][i] = arr[0][i] + Integer.max(dp[1][i - 1], dp[1][i - 2]);
				dp[1][i] = arr[1][i] + Integer.max(dp[0][i - 1], dp[0][i - 2]);
//				System.out.println("dp[0][" + i +"] : " + dp[0][i]);
//				System.out.println("dp[1][" + i +"] : " + dp[1][i]);
			}
			int sol = Integer.max(dp[0][n - 1], dp[1][n - 1]);
			System.out.println(sol);
		}
		return ;
	}
}

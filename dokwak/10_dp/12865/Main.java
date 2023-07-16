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
		int [][] dp = new int [101][100001];
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 100001; j++) {
				dp[i][j] = 0;
			}
		}
		int max_w = m;
		int[][] item = new int[n][2];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			item[i][0] = Integer.parseInt(st.nextToken());
			item[i][1] = Integer.parseInt(st.nextToken());
			int cur_weight = item[i][0];
			int cur_value = item[i][1];
			for (int w = 0; w < cur_weight; w++) {
				dp[i + 1][w] = dp[i][w];
			}
			for (int w = item[i][0]; w <= max_w; w++) {
				if (dp[i][w - cur_weight] + cur_value > dp[i][w])
					dp[i + 1][w] = dp[i][w - cur_weight] + cur_value;
				else
					dp[i + 1][w] = dp[i][w];
			}
		}
		System.out.println(dp[n][max_w]);
//		for (int i = 0; i < n; i++) {
//			System.out.println(item[i][0] + ", " + item[i][1]);
//		}
		return ;
	}
}

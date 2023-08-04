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
		int []app_mem = new int[n];
		int []app_cost = new int[n];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			app_mem[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			app_cost[i] = Integer.parseInt(st.nextToken());
		}
		int [][]dp = new int [101][100001];//app + 1, cost
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 100001; j++) {
				dp[i][j] = 0;
			}
		}
		int min_cost = 1000001;
		for (int i = 0; i < n; i++) {
			int cur_mem = app_mem[i];
			int cur_cost = app_cost[i];
			for (int cost_i = 0; cost_i < cur_cost; cost_i++) {
				dp[i + 1][cost_i] = dp[i][cost_i];
			}
			for (int cost_i = cur_cost; cost_i < 100001; cost_i++) {
				dp[i + 1][cost_i] = Integer.max(dp[i][cost_i - cur_cost] + cur_mem, dp[i][cost_i]);
				if (dp[i + 1][cost_i] >= m && cost_i < min_cost)
				{
					min_cost = cost_i;
					break;
				}
			}
		}
		System.out.print(min_cost);
		return ;
	}
}

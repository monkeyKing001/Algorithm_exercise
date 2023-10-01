import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int query;
	static int map[][];
	static long dp[][];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		query = m;
		map = new int[1025][1025];
		dp = new long[1025][1025];
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 1; j < n + 1; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (j == 1 && i == 1)
					dp[i][j] = map[i][j];
				if (j > 1)
					dp[i][j] = dp[i][j - 1] + map[i][j];
				if (j == 1 && i != 1)
					dp[i][j] = dp[i - 1][n] + map[i][j];
			}
		}
		for (int i = 0; i < n + 1; i++) {
			if (i == 0)
				dp[i][0] = 0;
			else
				dp[i][0] = dp[i - 1][n];
		}
//		for (int i = 1; i < n + 1; i++) {
//			for (int j = 0; j < n + 1; j++) {
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		for (int q_i = 0; q_i < query; q_i++) {
			st = new StringTokenizer(br.readLine()," ");
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			long sum = 0;
//			System.out.println("x1, y1, x2, y2 : "+x1+", "+y1+", "+x2+", "+y2);
			for (int x_i = x1; x_i < x2 + 1; x_i++) {
//				System.out.println("adding : " +(dp[x_i][y2] - dp[x_i][y1 - 1]));
				sum += dp[x_i][y2] - dp[x_i][y1 - 1];
			}
			sb.append(Long.toString(sum));
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



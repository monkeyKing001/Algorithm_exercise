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
		int lastDay = n;
		int dp[][] = new int[m + 1][lastDay + 1];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int costDay = Integer.parseInt(st.nextToken());
			int pageNum = Integer.parseInt(st.nextToken());
			for (int j = 0; j < costDay && j <= lastDay; j++) {
				dp[i + 1][j] = dp[i][j];
			}
			for (int startDay = 0; startDay + costDay <= lastDay; startDay++) {
				int endDay = startDay + costDay;
				dp[i + 1][endDay] = Math.max(dp[i][startDay] + pageNum, dp[i][endDay]);
			}
		}
//		for (int i = 0; i <= m; i++) {
//			for (int j = 0; j < lastDay + 1; j++) {
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		System.out.println(dp[m][lastDay]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

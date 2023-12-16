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
		int T = n;
		long dp[] = new long [140];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		for (int i = 5; i < 101; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			m = Integer.parseInt(st.nextToken());
			sb.append(dp[m]);
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

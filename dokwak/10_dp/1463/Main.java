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
		int []dp = new int[1000001];
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		for (int i = 4; i <= n; i++) {
			int steps = Integer.MAX_VALUE;
			dp[i] = steps;
			if (i % 3 == 0)
				dp[i] = Integer.min(dp[i / 3] + 1, dp[i]);
			if (i % 2 == 0)
				dp[i] = Integer.min(dp[i / 2] + 1, dp[i]);
			dp[i] = Integer.min(dp[i - 1] + 1, dp[i]);
		}
		System.out.println(dp[n]);
		return ;
	}
}



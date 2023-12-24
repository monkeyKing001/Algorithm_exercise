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
		int dp[] = new int [n + 1];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 1; i < n + 1; i++) {
			dp[i] = Integer.parseInt(st.nextToken()) + dp[i - 1];
		}
		int sol = Integer.MIN_VALUE;
		for (int i = 0; i + m <= n; i++) {
			sol = Integer.max(sol, dp[i + m] - dp[i]);
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



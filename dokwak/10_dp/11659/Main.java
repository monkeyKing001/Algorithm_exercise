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
		long []dp = new long[100002];
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		dp[0] = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i < n + 1; i++) {
			int temp = Integer.parseInt(st.nextToken());
			dp[i] = dp[i - 1] + temp; 
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			System.out.println(dp[end] - dp[start - 1]);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

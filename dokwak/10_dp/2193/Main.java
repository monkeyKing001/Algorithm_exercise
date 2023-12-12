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
		long dp [] = new long [101];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 2;
		for (int i = 4; i < 101; i++) {
			dp[i] = dp[i - 2] + dp[i - 1];
		}
		sb.append(dp[n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



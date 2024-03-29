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
		int []steps = new int [n + 1];
		int []dp = new int [n + 1];
		dp[0] = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			steps[i + 1] = Integer.parseInt(st.nextToken());;
		}
		for (int i = 1; i <= n; i++) {
			if (i <= 2){
				dp[i] = dp[i - 1];
			}
			else
				dp[i] = Integer.max(dp[i - 3] + steps[i - 1], dp[i - 2]);
			dp[i] += steps[i];
		}
		sb.append(dp[n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

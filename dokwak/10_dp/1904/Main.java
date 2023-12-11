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
		int mod = 15746;
		int dp[] = new int [1000001];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i < 1000001; i++) {
			dp[i] = ((dp[i - 1] % mod) + (dp[i - 2] % mod)) % mod ;
		}
		sb.append(dp[n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



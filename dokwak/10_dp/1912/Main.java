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
		int arr[] = new int[n];
		int dp[] = new int[n];
		int sol = Integer.MIN_VALUE;
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			if (i == 0)
				dp[i] = arr[i];
			else
				dp[i] = Integer.max(dp[i - 1] + arr[i], arr[i]);
			sol = Integer.max(sol, dp[i]);
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



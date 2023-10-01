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
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			steps[i + 1] = Integer.parseInt(st.nextToken());
		}
		for (int i = 1; i < n + 1; i++) {
			if (i == 1)
				dp[i] = steps[1];
			else if (i == 2)
				dp[i] = dp[1] + steps[2];
			else if (i >= 3)
				dp[i] = Integer.max(dp[i - 2], dp[i - 3] + steps[i - 1]) + steps[i];
		}
		System.out.print(dp[n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



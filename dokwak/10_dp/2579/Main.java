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
		for (int i = 1; i < n + 1; i++) {
			steps[i] = Integer.parseInt(br.readLine());
			if (i == 1)
				dp[1] = steps[1];
			else if (i == 2)
				dp[2] = steps[1] + steps[2];
			else if (i >= 3)
				dp[i] = Integer.max(dp[i - 2], dp[i - 3] + steps[i - 1]) + steps[i];
		}
//		for (int i = 1; i < n + 1; i++) {
//			System.out.println(steps[i]);
//		}
		System.out.println(dp[n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



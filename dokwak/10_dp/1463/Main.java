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
		for (int i = 1; i < n + 1; i++) {
			dp[i] = 0;	
		}
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		for (int i = 4; i < n + 1; i++) {
			int step = 100000001;
			if (i % 3 == 0)
				step = Integer.min(dp[i / 3] + 1, step);
			if (i % 2 == 0)
				step = Integer.min(dp[i / 2] + 1, step);
			step = Integer.min(dp[i - 1] + 1, step);
			dp[i] = step;
		}
		System.out.println(dp[n]);
//		for (int i = 0; i < n + 1; i++) {
//			System.out.println(dp[i]);
//		}
//		bw.write(sb.toString());
//		bw.flush();
		return ;
	}
}



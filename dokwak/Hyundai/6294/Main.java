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
		int [] arr = new int[n + 1];
		int [] dp = new int[n + 1];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n + 1; i++) {
			if (i == 0)
			{
				arr[i] = 0;
				continue;
			}
			arr[i] = Integer.parseInt(st.nextToken());
		}
		dp[1] = arr[1];
		for (int i = 1; i < n + 1; i++) {
			dp[i] = arr[i] + dp[i - 1];
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			int len = end - start + 1;
			int sum = dp[end] - dp[start - 1];
			System.out.println(sum);
			float sol = sum / (float)len;
			sb.append(String.format("%.2f", sol) + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



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
		int []dp = new int[50001];
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;
		for (int i = 1; i < 50001; i++) {
			dp[i] = 5;
			int temp = 1;
			int sub = temp * temp;
			while (i - sub >= 0)
			{
				dp[i] = Integer.min(dp[i], dp[i - sub] + 1);
				temp++;
				sub = temp * temp;
			}
		}
		System.out.println(dp[n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

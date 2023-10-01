import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dp[][];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		dp = new int [12][5];
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 4; j++) {
				dp[i][j] = 0;
			}
		}
		//make 1
		dp[1][1] = 1;
		dp[1][4] = 1;
		//make 2
		dp[2][1] = dp[1][4];
		dp[2][2] = 1;
		dp[2][4] = dp[2][1] + dp[2][2] + dp[2][3];
		//make 3
		dp[3][1] = dp[2][4];
		dp[3][2] = dp[1][4];
		dp[3][3] = 1;
		dp[3][4] = dp[3][1] + dp[3][2] + dp[3][3];
		for (int i = 4; i < 12; i++) {
			dp[i][1] = dp[i - 1][4];
			dp[i][2] = dp[i - 2][4];
			dp[i][3] = dp[i - 3][4];
			dp[i][4] = dp[i][1] + dp[i][2] + dp[i][3];
		}
		n = Integer.parseInt(st.nextToken());
		int T = n;
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			System.out.println(dp[num][4]);
		}

		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int mod = 1000000000;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		//init
		int [][][]dp = new int[101][10][1 << 10];
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < (1 << 10); k++) {
					dp[i][j][k] = 0;
				}
			}
		}

		//1 digit num
		for (int i = 1; i < 10; i++) {
			dp[1][i][1 << i] = 1;
		}
		
		//make dp
		for (int layer = 1; layer < n; layer++) {
			for (int last_num = 0; last_num < 10; last_num++) {
				int post_num = last_num + 1;
				int prev_num = last_num - 1;
				for (int bits = 0; bits < (1 << 10); bits++) {
					if (prev_num > -1)
					{
						dp[layer + 1][prev_num][bits | 1 << prev_num] += dp[layer][last_num][bits];
						dp[layer + 1][prev_num][bits | 1 << prev_num] %= mod;
					}
					if (post_num < 10)
					{
						dp[layer + 1][post_num][bits | 1 << post_num] += dp[layer][last_num][bits];
						dp[layer + 1][post_num][bits | 1 << post_num] %= mod;
					}
				}
			}
		}
		long sol = 0;
		for (int i = 0; i < 10; i++) {
			sol += dp[n][i][(1 << 10) - 1];
			sol %= mod;
		}
		System.out.println(sol);
		return ;
	}
}



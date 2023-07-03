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
		long [][][]dp = new long[101][10][(1 << 10)];
		for (int length = 0; length < 101; length++) {
			for (int last_num = 0; last_num < 10; last_num++) {
				for (int bits = 0; bits < (1 << 10); bits++) {
					dp[length][last_num][bits] = 0;	
				}
			}
		}
		//init 2
		for (int last_num = 1; last_num < 10; last_num++) {
			int bits = 1 << last_num;
			dp[1][last_num][bits] = 1;
		}
		for (int length = 1; length < n; length++) {
			for (int last_num = 0; last_num < 10; last_num++) {
				for (int bits = 0; bits < ((1 << 10)); bits++) {
					int next_bits = -1;
					if (last_num > 0)
					{
						next_bits = bits | (1 << (last_num - 1));
						dp[length + 1][last_num - 1][next_bits] += dp[length][last_num][bits];
						dp[length + 1][last_num - 1][next_bits] %= mod;
					}
					if (last_num < 9)
					{
						next_bits = bits | (1 << (last_num + 1));
						dp[length + 1][last_num + 1][next_bits] += dp[length][last_num][bits];
						dp[length + 1][last_num + 1][next_bits] %= mod;
					}
				}
			}
		}
		long sol = 0;
		for (int last_num = 0; last_num < 10; last_num++) {
			sol += dp[n][last_num][1023];
			sol %= mod;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



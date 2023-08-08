import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int mod =  1000000007;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			long [][]dp = new long[10001][1 << 4];
			String info = br.readLine();
			//init
			for (int i = 0; i < 10001; i++) {
				for (int j = 0; j < 1 << 4; j++) {
					dp[i][j] = 0;
				}
			}

			//day 0
			dp[0][1] = 1;
			for (int i = 0; i < info.length(); i++) {
				int charge = info.charAt(i) - 'A';
				for (int cur_mem_bits = 0; cur_mem_bits < 1 << 4; cur_mem_bits++) {
					for (int tomorrow_mem_bits = 0; tomorrow_mem_bits < 1 << 4; tomorrow_mem_bits++) {
						if ((tomorrow_mem_bits & (1 << charge)) != 0 &&
								(cur_mem_bits & tomorrow_mem_bits) != 0)
						{
							dp[i + 1][tomorrow_mem_bits] += dp[i][cur_mem_bits]; 
							dp[i + 1][tomorrow_mem_bits] %= mod;
						}
					}
				}
			}
			long sol = 0;
			for (int i = 0; i < (1 << 4); i++) {
				sol += (dp[info.length()][i] % mod);
				sol %= mod;
			}
			sb.append("#" + (t_i + 1) + " " + sol + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

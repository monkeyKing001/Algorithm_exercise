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
			String str = br.readLine();
			int days = str.length();
			int key = 0;
			int charge = 0;
			int case_num = 0;
			long sol = 0l;
			long [][]dp = new long[days + 1][(1 << 4)];
			for (int i = 0; i < 16; i++) {
				dp[0][i] = 0;
			}
//			System.out.println("test_i, str, str_len : " + t_i + ", " + str + ", " + days);
			dp[0][1 << 0] = 1;
			for (int i = 0; i < days; i++) {
//				System.out.println("day : " + (i + 1));
				int charge_tomorrow = str.charAt(i) - 'A';
//				System.out.println("tomorrow charge : " + (char)(charge_tomorrow + 'A'));
				for (int bits = 0; bits < 16; bits++) {
					int today_bits = bits;
					for (int tomorrow_bits = 0; tomorrow_bits < 16; tomorrow_bits++) {
						if ((tomorrow_bits & (1 << charge_tomorrow)) != 0 && (today_bits & tomorrow_bits) != 0)
						{
							dp[i + 1][tomorrow_bits] += dp[i][today_bits];
							dp[i + 1][tomorrow_bits] %= mod;
//							System.out.println("adding tomorrow_bits : " + tomorrow_bits);
						}
					}
					
				}
			}
			for (int i = 0; i < 16; i++) {
//				System.out.println("bits, val : " + i + ", " +dp[days][i] );
				sol += dp[days][i];
				sol %= mod;
			}
			sb.append("#" + (t_i + 1) + " " + sol + "\n");
			
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

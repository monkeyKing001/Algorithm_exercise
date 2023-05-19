import java.util.*;
import java.io.*;
import java.math.*;

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
		int []dp = new int[510];
		int []two_n_five = new int[2];
		two_n_five[0] = 0;
		two_n_five[1] = 0;
		dp[0] = 0;
		for (int i = 1; i < 501; i++) {
			int mult_num = i;
			dp[i] = dp[i - 1];
			if (mult_num % 5 == 0)
			{
				while (two_n_five[0] > 0 && mult_num != 0 && mult_num % 5 == 0)
				{
					dp[i]++;
					mult_num/= 5;
					two_n_five[0]--;
				}
			}
			if (mult_num % 2 == 0)
			{
				while (two_n_five[1] > 0 && mult_num != 0 && mult_num % 2 == 0)
				{
					dp[i]++;
					mult_num/= 2;
					two_n_five[1]--;
				}
			}
			while (mult_num != 0 && mult_num % 2 == 0)
			{
				two_n_five[0]++;
				mult_num /= 2;
			}
			while (mult_num != 0 && mult_num % 4 == 0)
			{
				two_n_five[1]++;
				mult_num /= 5;
			}
		}
		System.out.println(dp[n]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

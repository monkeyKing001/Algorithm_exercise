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
		int day[] = new int [n + 1];
		int pay[] = new int [n + 1];
		int dp[] = new int [n + 2];
		day[0] = 0;
		pay[0] = 0;
		dp[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int dayNeed = Integer.parseInt(st.nextToken());
			int payGet = Integer.parseInt(st.nextToken());
			day[i] = dayNeed;
			pay[i] = payGet;
		}
		int max_pay = 0;
		for (int i = 1; i < n + 1; i++) {
			int cur_day = i;
			dp[cur_day] = Integer.max(dp[cur_day], dp[cur_day - 1]);
			int next_day = cur_day + day[i];
			if (next_day <= n + 1){
				dp[next_day] = Integer.max(dp[next_day], dp[cur_day] + pay[cur_day]);
				max_pay = Integer.max(max_pay, dp[next_day]);
			}
		}
//		for (int i = 1; i < n + 1; i++) {
//			System.out.print(dp[i] +  " ");
//		}
//		System.out.println();
		System.out.println(max_pay);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



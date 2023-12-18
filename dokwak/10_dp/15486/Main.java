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
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int dayNeed = Integer.parseInt(st.nextToken());
			int payGet = Integer.parseInt(st.nextToken());
			day[i] = dayNeed;
			pay[i] = payGet;
		}
		for (int i = 1; i < n + 1; i++) {
			int curDay = i;
			int curPay = pay[i];
			int costDay = day[i];
			dp[curDay] = Integer.max(dp[curDay - 1], dp[curDay]);
			if (curDay + costDay <= n + 1)
				dp[curDay + costDay] = Integer.max(dp[curDay + costDay], dp[curDay] + curPay);
//			System.out.print("day : " + curDay + " ");
//			for (int j = 1; j < n + 2; j++) {
//				System.out.print(dp[j] + " ");
//			}
//			System.out.println();
		}
		dp[n + 1] = Integer.max(dp[n], dp[n + 1]);
		System.out.println(dp[n + 1]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



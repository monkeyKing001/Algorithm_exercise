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
		int dp[] = new int[n + 2];
		int info[][] = new int [n + 2][2];
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int day = Integer.parseInt(st.nextToken());
			int pay = Integer.parseInt(st.nextToken());
			info[i][0] = day;
			info[i][1] = pay;
		}
		for (int i = 1; i < n + 1; i++) {
			int day = info[i][0];
			int pay = info[i][1];
			for (int j = i + day; j < n + 2; j++) {
				dp[j] = Integer.max(dp[j], dp[i] + pay);
			}
//			for (int j = 1; j < n + 2; j++) {
//				System.out.print(dp[j] + " ");
//			}
//			System.out.println();
		}
		sb.append(dp[n + 1]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



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
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		int [][]map = new int[n + 1][n + 1];
		int dp[][][] = new int[2][m + 1][3];//car, stage, [r, c, cost]
		dp[0][0][0] = 1;//r
		dp[0][0][1] = 1;//c
		dp[0][0][2] = 0;//cost
		dp[1][0][0] = n;//r
		dp[1][0][1] = n;//c
		dp[1][0][2] = 0;//cost
		dp[0][1][2] = 0;
		dp[1][1][2] = 0;
		for(int i = 0 ; i < m; i++){
			st = new StringTokenizer(br.readLine()," ");
			int target_r = Integer.parseInt(st.nextToken());
			int target_c = Integer.parseInt(st.nextToken());
			for (int j = 0; j < 2; j++){
				dp[j][i + 1][0] = target_r;
				dp[j][i + 1][1] = target_c;
				int prev_r = dp[j][i][0];
				int prev_c = dp[j][i][1];
				dp[j][i  + 1][2] = (Math.abs(prev_r - target_r) + Math.abs(prev_c - target_c));
			}
		}
		for (int i = 0; i < 2; i++) {
			System.out.print(i);
			System.out.print("'s cost : ");
			for (int j = 0; j < m + 1; j++) {
				System.out.print(dp[i][j][2] + " ");
			}
			System.out.println();
		}
		int sol = Integer.min(dp[0][m][2], dp[1][m][2]);
		System.out.println(sol);
		return ;
	}
}



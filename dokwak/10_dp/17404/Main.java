import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		int n = Integer.parseInt(br.readLine());
		Long [][] cost = new Long [n][3];
		Long [][] dp0 = new Long [n][3];
		Long [][] dp1 = new Long [n][3];
		Long [][] dp2 = new Long [n][3];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			Long r, g, b;
			r = Long.parseLong(st.nextToken());
			g = Long.parseLong(st.nextToken());
			b = Long.parseLong(st.nextToken());
			cost[i][0] = r;
			cost[i][1] = g;
			cost[i][2] = b;
		}
		//input
		dp0[0][0] = cost[0][0];
		dp0[0][1] = (long)Integer.MAX_VALUE;
		dp0[0][2] = (long)Integer.MAX_VALUE;
		dp1[0][0] = (long)Integer.MAX_VALUE;
		dp1[0][1] = cost[0][1];
		dp1[0][2] = (long)Integer.MAX_VALUE;
		dp2[0][0] = (long)Integer.MAX_VALUE;
		dp2[0][1] = (long)Integer.MAX_VALUE;
		dp2[0][2] = cost[0][2];
		for (int i = 1; i < n; i++) {
			dp0[i][0] = cost[i][0] + Long.min(dp0[i - 1][1], dp0[i - 1][2]);	
			dp0[i][1] = cost[i][1] + Long.min(dp0[i - 1][0], dp0[i - 1][2]);	
			dp0[i][2] = cost[i][2] + Long.min(dp0[i - 1][0], dp0[i - 1][1]);	
			dp1[i][0] = cost[i][0] + Long.min(dp1[i - 1][1], dp1[i - 1][2]);	
			dp1[i][1] = cost[i][1] + Long.min(dp1[i - 1][0], dp1[i - 1][2]);	
			dp1[i][2] = cost[i][2] + Long.min(dp1[i - 1][0], dp1[i - 1][1]);	
			dp2[i][0] = cost[i][0] + Long.min(dp2[i - 1][1], dp2[i - 1][2]);	
			dp2[i][1] = cost[i][1] + Long.min(dp2[i - 1][0], dp2[i - 1][2]);	
			dp2[i][2] = cost[i][2] + Long.min(dp2[i - 1][0], dp2[i - 1][1]);	
		}
		long sol = Long.min(dp1[n-1][0], dp2[n-1][0]);
		if (sol > Long.min(dp0[n-1][1], dp2[n-1][1]))
			sol = Long.min(dp0[n-1][1], dp2[n-1][1]);
		if (sol > Long.min(dp0[n-1][2], dp1[n-1][2]))
			sol = Long.min(dp0[n-1][2], dp1[n-1][2]);
		//n = Long.parseInt(st.nextToken());
		System.out.println(sol);
		return ;
	}
}


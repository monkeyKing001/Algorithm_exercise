import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int end;
	static int max = 987654321;
	static int cost[][];
	static int dp[][];
	//find the optimum(minimum) cost to visit all other not visited nodes when already visited as bits masked.
	public static int TSP(int cur, int visited){
		//all visited, now return the cost to back start point(0)
		if (visited == end)
		{
			if (cost[cur][0] == 0)
				return max;
			return cost[cur][0];
		}
		if (dp[cur][visited] != 0)//already visited
			return (dp[cur][visited]);
		//traverse all the other not visited node;
		dp[cur][visited] = max;
		for (int next = 0; next < n; next++) {
			if ((visited & (1 << next)) != 0) //already visited nodes. pass.
				continue;
			if (cost[cur][next] == 0) //no way
				continue;
			dp[cur][visited] = Integer.min(dp[cur][visited], TSP(next, visited | (1 << next)) + cost[cur][next]);
		}
		return (dp[cur][visited]);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		n = Integer.parseInt(st.nextToken());
		end = (1 << n) - 1;
		cost = new int[n][n];
		for (int i = 0; i < n; i++) {
		st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < n; j++) {
				cost[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		dp = new int[n][(1 << n)];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (1 << n); j++) {
				dp[i][j] = 0;
			}
		}
		long sol = TSP(0, 1);
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

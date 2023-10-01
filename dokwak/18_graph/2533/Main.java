import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int visited[];
	static ArrayList<Integer> adj_list [];
	static int dp[][];
	
	public static void rec(int cur, int parent){
		dp[cur][0] = 0;
		dp[cur][1] = 1;
		for (int i = 0; i < adj_list[cur].size(); i++) {
			int next = adj_list[cur].get(i);
			if (next != parent){
				rec(next, cur);
				//in case cur node is not early adapter
				dp[cur][0] += dp[next][1];
				//in case cur node is early adapter
				dp[cur][1] += Integer.min(dp[next][1], dp[next][0]);
			}
		}
	}
		


	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		visited = new int[n + 1];
		dp= new int [n + 1][2];
		adj_list = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
			for (int j = 0; j < 2; j++) {
				dp[i][j] = -1;
			}
		}
		//input
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			adj_list[u].add(v);
			adj_list[v].add(u);
		}
		int root = 1;
		rec(root, -1);
		int sol = Integer.min(dp[1][0], dp[1][1]);
//		for (int i = 1; i < n + 1; i++) {
//			System.out.println(dp[i][0] + "\t" + dp[i][1]);
//		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

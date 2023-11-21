import java.util.*;
import java.io.*;

public class Main{
	static int n, m, target;
	static int max = 100001;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		target = Integer.parseInt(st.nextToken());
		int dp[][] = new int[n + 1][n + 1];
		ArrayList<int[]> g[] = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				dp[i][j] = max;
				g[i] = new ArrayList<>();
				if (i == j)
				{
					dp[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int cur_cost = Integer.parseInt(st.nextToken());
			dp[u][v] = cur_cost;
				int []edge = new int[2];
				edge[0] = v;
				edge[1] = cur_cost;
				g[u].add(edge);
		}
		for (int i = 1; i < n + 1; i++) {
			int start = i;
			PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comparator<int[]>(){
				@Override
				public int compare(int e1[], int e2[]){
					return (Integer.compare(e1[2], e2[2]));
				}
			});
			for (int start_e = 0; start_e < g[start].size(); start_e++) {
				int []info = new int[3];
				info[0] = start;
				info[1] = g[start].get(start_e)[0];
				info[2] = g[start].get(start_e)[1];
				pq.add(info);
			}
			while (pq.size() != 0){
				int cur_info[] = pq.poll();
				int bridge = cur_info[1];
				int cur_cost = cur_info[2];
				for (int b_e = 0; b_e < g[bridge].size(); b_e++) {
					int next_v = g[bridge].get(b_e)[0];
					if (dp[start][next_v] > dp[bridge][next_v] + cur_cost)
					{
						int next_info[] = new int[3];
						next_info[0] = start;
						next_info[1] = next_v;
						next_info[2] = dp[bridge][next_v] + cur_cost;
						dp[start][next_v] = dp[bridge][next_v] + cur_cost;
						pq.add(next_info);
					}
				}
			}
		}
		int sol = -1;
		for (int i = 1; i < n + 1; i++) {
			sol = Integer.max(sol, dp[i][target] + dp[target][i]);
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

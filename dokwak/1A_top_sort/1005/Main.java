import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static 	Queue<Integer> q = new LinkedList<>();
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int t = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < t; t_i++) {
			//var
			q.clear();
			st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			int []time = new int[n + 1];
			int []indegree = new int[n + 1];
			int []time_dp = new int[n + 1];
			ArrayList<Integer> []top = new ArrayList[n + 1];//outdegree

			//init
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 1; i < n + 1; i++) {
				top[i] = new ArrayList<>();
				indegree[i] = 0;
				time[i] = Integer.parseInt(st.nextToken());
				time_dp[i] = -1;
			}

			//in-outdegree
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				indegree[v]++;
				top[u].add(v);
			}
			st = new StringTokenizer(br.readLine(), " ");
			int target = Integer.parseInt(st.nextToken());
			//Queue for indegree 0 buildings
			for (int b = 1; b < n + 1; b++) {
				if (indegree[b] == 0)
				{
					q.add(b);
					time_dp[b] = time[b];
				}
			}
			while (q.size() != 0)
			{
				int cur_b = q.poll();
				int cur_time = time_dp[cur_b];
				for (int top_i = 0; top_i < top[cur_b].size(); top_i++) {
					int to_b = top[cur_b].get(top_i);
					indegree[to_b]--;
					time_dp[to_b] = Integer.max(cur_time + time[to_b], time_dp[to_b]);
					if (indegree[to_b] == 0)
						q.add(to_b);
				}
			}
			System.out.println(time_dp[target]);
		}
		return ;
	}
}

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
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine(), " ");
		int start = Integer.parseInt(st.nextToken());
		int inf = 20000000;
		int [] cost_to_visit = new int [n + 1];
		ArrayList<int[]> g[] = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
			cost_to_visit[i] = inf;
			if (i == start)
				cost_to_visit[i] = 0;
		}
		//priority_queue
		PriorityQueue<int []> pq = new PriorityQueue<>(new Comparator<int []>()
				{
					@Override
					public int compare(int []e1, int []e2)
					{
						return (Integer.compare(e1[2], e2[2]));
					}
				});
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1, v2, cost;
			int []edge = new int [3];
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());
			cost = Integer.parseInt(st.nextToken());
			edge[0] = v1;
			edge[1] = v2;
			edge[2] = cost;
			g[v1].add(edge);
			if (v1 == start)
			{
				cost_to_visit[v2] = Integer.min(cost_to_visit[v2], cost);
				pq.add(edge);
			}
		}
		while (pq.size() != 0)
		{
			int []edge = pq.poll();
			int connected_v = edge[1];
			int connected_cost = edge[2];
			if (cost_to_visit[connected_v] < connected_cost)
				continue;
			for (int i = 0; i < g[connected_v].size(); i++) {
				int []edge_of_connected_v = g[connected_v].get(i);
				int next_v, next_cost;
				next_v = edge_of_connected_v[1];
				next_cost = edge_of_connected_v[2];
				if (cost_to_visit[next_v] > connected_cost + next_cost)
				{
					cost_to_visit[next_v] = connected_cost + next_cost;
					int [] next_edge = new int[3];
					next_edge[0] = connected_v;
					next_edge[1] = next_v;
					next_edge[2] = cost_to_visit[next_v];
					pq.add(next_edge);
				}
			}
		}
		for (int i = 1; i < n + 1; i++) {
			if (cost_to_visit[i] == inf)
				sb.append("INF\n");
			else
				sb.append(Integer.toString(cost_to_visit[i]) + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

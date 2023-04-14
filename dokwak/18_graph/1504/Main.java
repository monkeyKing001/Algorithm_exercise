//Djikstra solution retry
//start 04/13 21:44
//end
import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int inf = 20000000;
	static ArrayList<int[]> adj_list[] = new ArrayList[801];

	public static void Djikstra(int []cost_to_visit, int start)
	{
		PriorityQueue<int []> pq = new PriorityQueue<>(new Comparator<int []>()
				{
					@Override
					public int compare(int []e1, int []e2)
					{
						return (Integer.compare(e1[2], e2[2]));
					}
				});
		for (int i = 0; i < n + 1; i++) {
			cost_to_visit[i] = inf;
		}
		cost_to_visit[start] = 0;
		int []start_edge = new int[3];
		start_edge[0] = 0;
		start_edge[1] = start;
		start_edge[2] = 0;
		pq.add(start_edge);
		while (pq.size() != 0)
		{
			int []connected_edge = pq.poll();
			int connected_v = connected_edge[1];
			int connected_cost = connected_edge[2];
			if (cost_to_visit[connected_v] > connected_cost)
				continue ;
			for (int i = 0; i < adj_list[connected_v].size(); i++) {
				int []next_edge = adj_list[connected_v].get(i);
				int next_v = next_edge[1];
				int next_cost = next_edge[2];
				if (cost_to_visit[next_v] > connected_cost + next_cost)
				{
					int [] new_edge = new int[3];
					cost_to_visit[next_v] = connected_cost + next_cost;
					new_edge[0] = connected_v;
					new_edge[1] = next_v;
					new_edge[2] = cost_to_visit[next_v];
					pq.add(new_edge);
				}
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
		m = Integer.parseInt(st.nextToken());
		int [] cost_of_start = new int[n + 1];
		int [] cost_of_v1 = new int[n + 1];
		int [] cost_of_v2 = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int u, v, cost;
			int []edge_u = new int[3];
			int []edge_v = new int[3];
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			cost = Integer.parseInt(st.nextToken());
			edge_u[0] = u;
			edge_u[1] = v;
			edge_u[2] = cost;
			edge_v[0] = v;
			edge_v[1] = u;
			edge_v[2] = cost;
			adj_list[u].add(edge_u);
			adj_list[v].add(edge_v);
		}
		//Djikstra from start
		int v1, v2;
		st = new StringTokenizer(br.readLine(), " ");
		v1 = Integer.parseInt(st.nextToken());
		v2 = Integer.parseInt(st.nextToken());
		Djikstra(cost_of_start, 1);
		//Djikstra from v1
		Djikstra(cost_of_v1, v1);
		//Djikstra from v2
		Djikstra(cost_of_v2, v2);
		//find path
		int sol = 0;
		//impossible case
		if (cost_of_start[v1] == inf || cost_of_start[v2] == inf || cost_of_start[n] == inf)
			sol = -1;
		else
			sol = Integer.min(cost_of_start[v1] + cost_of_v1[v2] + cost_of_v2[n], cost_of_start[v2] + cost_of_v2[v1] + cost_of_v1[n]);
		sb.append(Integer.toString(sol));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

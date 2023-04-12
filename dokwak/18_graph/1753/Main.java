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
		ArrayList<int []>[] ad_list = new ArrayList[n + 1];
		int []visited = new int [n + 1];
		int []cost_to_visit = new int [n + 1];
		for (int i = 0; i < n + 1; i++) {
			ad_list[i] = new ArrayList<int []>();
			if (i == start)
			{
				cost_to_visit[i] = 0;
				visited[i] = 1;
			}
			else
			{
				cost_to_visit[i] = inf;
				visited[i] = 0;
			}
		}
		PriorityQueue<int []> pq = new PriorityQueue<>(new Comparator<int []>(){
			@Override
			public int compare(int []e1, int []e2)
			{
				return (Integer.compare(e1[2], e2[2]));
			}
		});
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1, v2, cost;
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());
			cost = Integer.parseInt(st.nextToken());
			int [] edge = new int [3];
			edge[0] = v1;
			edge[1] = v2;
			edge[2] = cost;
			ad_list[v1].add(edge);
			if (v1 == start && cost_to_visit[v2] > cost)
			{
				cost_to_visit[v2] = cost;
				pq.add(edge);
			}
		}
		while (pq.size() != 0)
		{
			int cur_v,connected_v, connected_cost;
			cur_v = pq.peek()[0];
			connected_v = pq.peek()[1];
			connected_cost = pq.peek()[2];
			pq.poll();
			if (cost_to_visit[connected_v] != connected_cost)
				continue ;
			for (int i = 0; i < ad_list[connected_v].size(); i++) {
				int next_v, connected_n_next_cost;
				next_v = ad_list[connected_v].get(i)[1];
				connected_n_next_cost = ad_list[connected_v].get(i)[2];
				if (connected_cost + connected_n_next_cost < cost_to_visit[next_v])
				{
					cost_to_visit[next_v] = connected_cost + connected_n_next_cost;
					int [] ed = new int[3];
					ed[0] = connected_v;
					ed[1] = next_v;
					ed[2] = connected_n_next_cost;
					pq.add(ed);
				}
			}
		}
		for (int i = 1; i < n + 1; i++) {
			if (cost_to_visit[i] != inf)
				sb.append(Integer.toString(cost_to_visit[i]) + "\n");
			else
				sb.append("INF\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

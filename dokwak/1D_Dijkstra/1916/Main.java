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
		ArrayList<int[]>[] g = new ArrayList[n + 1];
		long []cost  = new long[n + 1];
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
			cost[i] = Integer.MAX_VALUE;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int cost_to = Integer.parseInt(st.nextToken());
			int []edge = new int[2];
			edge[0] = v;
			edge[1] = cost_to;
			g[u].add(edge);
		}
		st = new StringTokenizer(br.readLine()," ");
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int []e1, int []e2){
				return (Integer.compare(e1[1], e2[1]));
			}
		});
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		for (int i = 0; i < g[start].size(); i++) {
			int []edge = g[start].get(i);
			pq.add(edge);
		}
		while (pq.size() != 0){
			int []edge = pq.poll();
			int to_v = edge[0];
			int to_cost = edge[1];
			if (cost[to_v] > to_cost)
				cost[to_v] = to_cost;
			else
				continue;
			for (int i = 0; i < g[to_v].size(); i++) {
				int []next_edge = g[to_v].get(i);
				int next_v = next_edge[0];
				int next_cost = next_edge[1];
				if (cost[next_v] > to_cost + next_cost){
					int []next = new int[2];
					next[0] = next_v;
					next[1] = to_cost + next_cost;
					pq.add(next);
				}
			}
		}
		System.out.println(cost[end]);
		return ;
	}
}

import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int max = 1000000000;
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
		int cost[][] = new int[n + 1][n + 1];
		ArrayList<int[]> g[] = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
			for (int j = 0; j < n + 1; j++) {
				cost[i][j] = max;
				if (i == j)
					cost[i][j] = 0;
			}
		}
		//from, to, cost
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			public int compare(int []e1, int[] e2){
				return (Integer.compare(e1[2], e2[2]));
			}
		});
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int start = Integer.parseInt(st.nextToken());
			int dest = Integer.parseInt(st.nextToken());
			int to_cost = Integer.parseInt(st.nextToken());
			int info[] = new int[2];
			info[0] = dest;
			info[1] = to_cost;
			g[start].add(info);
		}
		st = new StringTokenizer(br.readLine()," ");
		int from = Integer.parseInt(st.nextToken());
		int to = Integer.parseInt(st.nextToken());
		int total_connected = 1;//from
		//Dijkstra start!
		for (int i = 0; i < g[from].size(); i++) {
			int edge[] = g[from].get(i);
			int start = from;
			int dest = edge[0];
			int to_cost = edge[1];
			int pq_edge[] = new int[3];
			pq_edge[0] = start;
			pq_edge[1] = dest;
			pq_edge[2] = to_cost;
			pq.add(pq_edge);
		}
		while(pq.size() != 0){
			int []edge = pq.poll();
			int cur_from = edge[0];
			int cur_to = edge[1];
			int cur_cost = edge[2];
			//already got min cost
			//if (cost[from][cur_to] < cost[from][cur_from] + cost[cur_from][cur_to]){
			if (cost[from][cur_to] < cur_cost){
				continue;
			}
			//cost[from][cur_to] = cost[from][cur_from] + cost[cur_from][cur_to];
			cost[from][cur_to] = cur_cost;
			for (int i = 0; i < g[cur_to].size(); i++) {
				int next_edge[] = g[cur_to].get(i);
				int next_from = cur_to;
				int next_to = next_edge[0];
				int next_cost = next_edge[1] + cost[from][cur_to];
				if (cost[from][next_to] > next_cost){
					int next_pq_edge[] = new int[3];
					next_pq_edge[0] = next_from;
					next_pq_edge[1] = next_to;
					next_pq_edge[2] = next_cost;
					pq.add(next_pq_edge);
				}
			}
		}
//		for (int i = 1; i < n + 1; i++) {
//			System.out.print(cost[from][i] + " ");
//		}
//		System.out.println();
		System.out.println(cost[from][to]);
		return ;
	}
}

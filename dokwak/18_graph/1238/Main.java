import java.util.*;
import java.io.*;

public class Main{
	static int n, m, x;
	static int [][]g;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		ArrayList<int[]>[]arr = new ArrayList[n + 1];
		int [][] g = new int [n + 1][n + 1];
		int [][] cost = new int[n + 1][n + 1];
		for (int i = 0; i < n + 1; i++) {
			arr[i] = new ArrayList<int[]>();
			for (int j = 0; j < n + 1; j++) {
				g[i][j] = 11000000;
				cost[i][j] = 11000000;
				if (i == j)
				{
					g[i][j] = 0;
					cost[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int [] edge = new int[2];
			edge[0] = v;
			edge[1] = c;
			arr[u].add(edge);
			g[u][v] = c;
			cost[u][v] = c;
		}
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int []e1, int []e2){
				return (Integer.compare(e1[2], e2[2]));
			}
		});
		for (int i = 1; i < n + 1; i++) {
			int start = i;
			pq.clear();
//			System.out.println("######## start #######  : " + start);
			for (int e = 0; e < arr[start].size(); e++) {
				int [] edge = arr[start].get(e);
				int[] next_edge = new int[3];
				next_edge[0] = start;
				next_edge[1] = edge[0];
				next_edge[2] = edge[1];//cost
				pq.add(next_edge);
			}
			while (pq.size() != 0) //all visited
			{
				int [] edge = pq.poll();
				int bridge_v = edge[0];
				int to_v = edge[1];
				int cost_to_v = edge[2];
				if (cost[start][to_v] > cost_to_v)
					cost[start][to_v] = cost_to_v;
				for (int e = 0; e < arr[to_v].size(); e++) {
					int next_v = arr[to_v].get(e)[0];//found not visited v
					int next_cost = arr[to_v].get(e)[1];
					if (cost[start][next_v] > cost[start][to_v] + next_cost)
					{
						int [] next_edge = new int[3];
						next_edge[0] = to_v;
						next_edge[1] = next_v;
						next_edge[2] = cost[start][to_v] + g[to_v][next_v];
						pq.add(next_edge);
					}
				}
			}
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				System.out.print(cost[i + 1][j + 1] + " ");
//			}
//			System.out.println();
//		}
		long sol = 0;
		for (int i = 1; i < n + 1; i++) {
			if (sol < cost[i][x] + cost[x][i])
				sol = cost[i][x] + cost[x][i];
		}
		System.out.print(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

import java.util.*;
import java.io.*;

public class Main{
	static int n, m, target;
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
		int [][]dp_cost = new int [n + 1][n + 1];
		ArrayList<int[]>[] arr = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			arr[i] = new ArrayList<>();
			for (int j = 0; j < n + 1; j++) {
				dp_cost[i][j] = 10000001;
				if (i == j)
					dp_cost[i][j] = 0;
			}
		}
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int []e1, int []e2){return (Integer.compare(e1[2], e2[2]));}
		});
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int from, to, temp_cost;
			from = Integer.parseInt(st.nextToken());
			to = Integer.parseInt(st.nextToken());
			temp_cost = Integer.parseInt(st.nextToken());
			int []cost_to = new int[2];
			cost_to[0] = to;
			cost_to[1] = temp_cost;
			arr[from].add(cost_to);
//			dp_cost[from][to] = temp_cost;
		}
		for (int start = 1; start < n + 1; start++) {
			pq.clear();
			for (int e_i = 0; e_i < arr[start].size(); e_i++) {
				int []pq_edge = new int [3];
				pq_edge[0] = start;//start
				pq_edge[1] = arr[start].get(e_i)[0];//to v
				pq_edge[2] = arr[start].get(e_i)[1];//cur_cost
				dp_cost[start][pq_edge[1]] = pq_edge[2];
				pq.add(pq_edge);
			}
			while(pq.size() != 0)
			{
				int [] p_edge = pq.poll();
				int from_v = p_edge[0];
				int to_v = p_edge[1];
				int to_cost = p_edge[2];
				for (int e_i = 0; e_i < arr[to_v].size(); e_i++) {
					int next_v;
					int cost_to_next_v;
					next_v = arr[to_v].get(e_i)[0];
					cost_to_next_v = to_cost + arr[to_v].get(e_i)[1];
					if (dp_cost[start][next_v] > cost_to_next_v)
					{
//						System.out.println("found way to, cost : " + next_v + ", " + cost_to_next_v);
//						System.out.println("bridge : " + to_v);
						dp_cost[start][next_v] = cost_to_next_v;
						int [] next_edge = new int[3];
						next_edge[0] = to_v;
						next_edge[1] = next_v;
						next_edge[2] = cost_to_next_v;
						pq.add(next_edge);
					}
				}
			}
		}
//		for (int i = 1; i < n + 1; i++) {
//			for (int j = 1; j < n + 1; j++) {
//				System.out.print(dp_cost[i][j] + " ");
//			}
//			System.out.println();
//		}
		int sol = -1;
		for (int i = 1; i < n + 1; i++) {
			if (sol < dp_cost[i][target] + dp_cost[target][i])
				sol = dp_cost[i][target] + dp_cost[target][i];
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

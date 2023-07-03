import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<int[]> adj_list[] = new ArrayList[10001];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int []cost = new int[n + 1];
		int []cost_from_start = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
			cost[i] = 100000001;
			cost_from_start[i] = 1000000001;
			if (i == 1)
				cost[i] = 0;
		}
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int[] e1, int[] e2){
				return (Integer.compare(e1[1], e2[1]));
			}
		});
		String buf = br.readLine();
		while (buf != null)
		{
			st = new StringTokenizer(buf, " ");
			int p = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int cost_to_visit = Integer.parseInt(st.nextToken());
			int []e = new int[2];
			int []e2 = new int[2];
			e[0] = c;
			e[1] = cost_to_visit;
			e2[0] = p;
			e2[1] = cost_to_visit;
			adj_list[p].add(e);
			adj_list[c].add(e2);
			if (p == 1)
				pq.add(e);
			buf = br.readLine();
		}
		while (pq.size() != 0){
			int [] e = pq.poll();
			int cur_v = e[0];
			int cur_cost = e[1];
//			System.out.println("now, cost to visit = " + cur_v + " is " + cur_cost);
			if (cost[cur_v] > cur_cost)
				cost[cur_v] = cur_cost;
			for (int e_i = 0; e_i < adj_list[cur_v].size(); e_i++) {
				int []temp_e = adj_list[cur_v].get(e_i);
				int next_v = temp_e[0];
				int next_cost = temp_e[1] + cur_cost;
				if (cost[next_v] > next_cost)
				{
					int []next_e = new int[2];
					next_e[0] = next_v;
					next_e[1] = next_cost;
//					System.out.println("add pq : " + next_v);
//					System.out.println("cost to visit : " + next_cost);
					pq.add(next_e);
				}

			}
		}
		int sol = -1;
		int start = -1;
		for (int i = 1; i < n + 1; i++) {
			if (sol < cost[i])
			{
				sol = cost[i];
				start = i;
			}
		}
		cost_from_start[start] = 0;
		for (int e_i = 0; e_i < adj_list[start].size(); e_i++) {
			int []e = adj_list[start].get(e_i);
			pq.add(e);
			cost_from_start[start] = e[1];
		}
		while (pq.size() != 0)
		{
			int []e = pq.poll();
			int cur_v = e[0];
			int cur_cost = e[1];
			if (cost_from_start[cur_v] > cur_cost)
				cost_from_start[cur_v] = cur_cost;
			for (int e_i = 0; e_i < adj_list[cur_v].size(); e_i++) {
				int []next_e = adj_list[cur_v].get(e_i);
				int next_v = next_e[0];
				int next_cost = cur_cost + next_e[1];
				if (cost_from_start[next_v] > next_cost)
				{
//					cost_from_start[next_v] = next_cost;
//					System.out.println("cost to visit " + next_v + " is " + next_cost);
					int []add_e = new int[2];
					add_e[0] = next_v;
					add_e[1] = next_cost;
					pq.add(add_e);
				}
			}
		}
		int cost_back = 0;
		for (int i = 1; i < n + 1; i++) {
			if (cost_back < cost_from_start[i])
				cost_back = cost_from_start[i];
		}
		//one more Dijkstra
		System.out.println(cost_back);
		return ;
	}
}

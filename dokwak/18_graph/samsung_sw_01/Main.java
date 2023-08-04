import java.util.*;
import java.io.*;

class Main
{
	static int max = 40000001;
	static int n, m;
	static ArrayList<int[]> []g;
	static int []visited_edge_g;
	static int temp_total_cost = Integer.MAX_VALUE;

	public static void travel(int cur, int next, int []visited, int [] visited_e){
		if (visited[next] == 1){
			System.out.println("found cycle! start, to : " + cur +", "+ next);
			for (int e_i = 0; e_i < g[cur].size(); e_i++) {
				int []e = g[cur].get(e_i);
				int e_i_g = e[0];
				int start = e[1];
				int cycle_next = e[2];
				int cost = e[3];
				if (cycle_next == next)
				{
					cal_cyc(start, cycle_next, visited, visited_e, cost);
					break;
				}
			}
			return ;
		}
		visited[next] = 1;
		for (int next_edge_i = 0; next_edge_i < g[next].size(); next_edge_i++) {
			int []next_edge = g[next].get(next_edge_i);
			int v_e_i = next_edge[0];
			if (visited_edge_g[v_e_i] != 0)
				continue ;
			visited_edge_g[v_e_i] = 1;
			visited_e[v_e_i] = 1;
			int next_v = next_edge[2];
			int []temp_visited = visited.clone();
			int []temp_visited_e = visited_e.clone();
			travel(next, next_v, temp_visited, temp_visited_e);
		}
	}
	public static void cal_cyc(int start, int cur, int []visited, int []visited_e, int acc_cost)
	{
		if (start == cur){
			System.out.println("end of cycle, acc cost : " + acc_cost);
			temp_total_cost = Integer.min(temp_total_cost, acc_cost);
			return ;
		}
		for (int e_i = 0; e_i < g[cur].size(); e_i++) {
			int []e = g[cur].get(e_i);
			int v_e_i = e[0];
			int next = e[2];
			int next_cost = e[3];
			System.out.println("searching cycle from cur, to next : " + cur +", "+ next);
			if (visited_e[v_e_i] == 1 && visited[next] == 1)
			{
				System.out.println("cycle! cur, next : " + cur +", "+ next);
				cal_cyc(start, next, visited, visited_e, acc_cost+ next_cost);
			}
		}
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			g = new ArrayList[n + 1];
			visited_edge_g = new int[m + 1];
			int []visited_v = new int[n + 1];
			int []visited_edge = new int[m + 1];
			for (int i = 0; i < n + 1; i++) {
				g[i] = new ArrayList<int[]>();
				visited_v[i] = 0;
			}
			for (int i = 0; i < m + 1; i++) {
				visited_edge[i] = 0;
				visited_edge_g[i] = 0;
			}
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine()," ");
				int edge_index = i;
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				int cost = Integer.parseInt(st.nextToken());
				int []edge = new int [4];
				edge[0] = edge_index;
				edge[1] = u;
				edge[2] = v;
				edge[3] = cost;
				g[u].add(edge);
			}
			for (int start_point = 1; start_point < n + 1; start_point++) {
				System.out.println("travel searching from " + start_point);
				for (int next_edge_i = 0; next_edge_i < g[start_point].size(); next_edge_i++) {
					int []next_edge = g[start_point].get(next_edge_i);
					int v_e_i = next_edge[0];
					if (visited_edge_g[v_e_i] != 0)
						continue ;
					int next_v = next_edge[2];
					int []temp_visited = visited_v.clone();
					int []temp_visited_e  = visited_edge.clone();
					System.out.println("go to " + next_v);
					visited_edge_g[v_e_i] = 1;
					temp_visited[start_point] = 1;
					temp_visited_e[v_e_i] = 1;
					travel(start_point, next_v, temp_visited, temp_visited_e);
				}
			}
			System.out.println("#" + (t_i + 1) + " " + temp_total_cost);
		}
		return ;
	}
}

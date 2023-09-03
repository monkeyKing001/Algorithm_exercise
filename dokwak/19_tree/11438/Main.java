import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[][] dp_parent;
	static int[] depth;
	public static void set_parent(int []move){
		int parent = move[0];
		int child = move[1];
		int cur_depth = move[2];
		dp_parent[child][0] = parent;
		for (int i = 1; i < 21; i++) {
			int up_depth = cur_depth - (1 << i);
			if (up_depth < 0)
				break;
			int half_parent = dp_parent[child][i - 1];
			dp_parent[child][i] = dp_parent[half_parent][i - 1];
		}
	}

	public static int find_lca(int u, int v){
		int lca = -1;

//		System.out.println("finding lca u, v : " + u +", "+v);
		//0. make v has deeper depth
		if (depth[u] > depth[v])
		{
			int temp = u;
			u = v;
			v = temp;
		}
		//1. make u, v depth same
		int diff = depth[v] - depth[u];
		while (diff != 0){
			int exp = 0;
			for (int i = 0; i < 21; i++) {
				if ((1 << i) > diff)
					break;
				exp = i;
			}
			v = dp_parent[v][exp];
			diff = depth[v] - depth[u];
		}
//		System.out.println("now u, v has same depth : " + depth[u] + ", " + depth[v]);
		//2. find lca
		int exp = 0;
		while (u != v){
			exp = 0;
			for (int i = 0; i < 21; i++) {
				int u_anc = dp_parent[u][i];
				int v_anc = dp_parent[v][i];
				if (u_anc == v_anc)
					break;
				else
					exp = i;
			}
			u = dp_parent[u][exp];
			v = dp_parent[v][exp];
		}
		lca = u;
		return (lca);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		ArrayList<Integer> [] adj_list = new ArrayList[n + 1];
		dp_parent = new int[n + 1][21];
		depth = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
			depth[i] = -1;
			for (int j = 0; j < 21; j++) {
				dp_parent[i][j] = -1;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			adj_list[u].add(v);
			adj_list[v].add(u);
		}
		Queue<int[]> q = new LinkedList<>();
		depth[1] = 0;
		for (int i = 0; i < adj_list[1].size(); i++) {
			int to_v = adj_list[1].get(i);
			int [] move = new int[3];
			move[0] = 1;//parent
			move[1] = to_v;
			move[2] = 1;//depth of child
			q.add(move);
		}
		//bfs first visit
		while(q.size() != 0){
			int []cur_move = q.poll();
			int cur_node = cur_move[0];
			int next_node = cur_move[1];
			int cur_depth = cur_move[2];
			if (depth[next_node] != -1)
				continue;
			depth[next_node] = cur_depth;
			//set parent
			set_parent(cur_move);
			for (int i = 0; i < adj_list[next_node].size(); i++) {
				int next_next_node = adj_list[next_node].get(i);
				if (depth[next_next_node] == -1){
					int [] next_move = new int[3];
					next_move[0] = next_node;
					next_move[1] = next_next_node;
					next_move[2] = cur_depth + 1;
					q.add(next_move);
				}
			}
		}
//		for (int i = 1; i < n + 1; i++) {
//			System.out.println("depth of " + i + " : " + depth[i]);
//		}
		st = new StringTokenizer(br.readLine()," ");
		int Q = Integer.parseInt(st.nextToken());
		for (int q_i = 0; q_i < Q; q_i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int lca = find_lca(u, v);
			sb.append(lca + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

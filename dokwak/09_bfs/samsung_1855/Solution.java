import java.util.*;
import java.io.*;

public class Solution{
	static int n, m;
	static ArrayList<Integer> [] g;
	static Queue<int []> q;
	static int [][]dp_parent;
	static int []depth;
	static int max_depth = 20;

	public static void set_anc(int []node){
		int cur_node = node[0];
		int cur_depth = node[1];
		int parent = node[2];
		dp_parent[cur_node][0] = parent;
		for (int i = 1; i < max_depth; i++) {
			int half_parent = dp_parent[cur_node][i - 1];
			if ((cur_depth - (1 << i)) < 0){
				break;
			}
			dp_parent[cur_node][i] = dp_parent[half_parent][i - 1];
//			System.out.println((1 << i) + "'s anc : " + dp_parent[half_parent][i - 1]);
		}
//		System.out.println(cur_node + "'s anc update complete!");
	}

	public static int get_distance(int p, int c){
		return (depth[c] - depth[p]);
	}

	public static int find_common_anc(int node1, int node2){
		int anc = -1;
		//make node2 a deeper one.
		if (depth[node1] > depth[node2])
		{
			int temp = node1;
			node1 = node2;
			node2 = temp;
		}
		int exp = 0;
		//binary jump up
		int diff = depth[node2] - depth[node1];
		while (diff > 0){
			for (int i = 0; i < max_depth; i++) {
				if ((1 << i) > diff)
					break;
				else
					exp = i;
			}
			node2 = dp_parent[node2][exp];
			diff = depth[node2] - depth[node1];
		}
		//same height now
		//find lowest common anc
//		System.out.println(node1 + ", " + node2 + " are on same depth : " + depth[node1]);
		while (node1 != node2)
		{
			exp = 0;
			for (int i = 0; i < max_depth; i++) {
				if (dp_parent[node1][i] != dp_parent[node2][i])
					exp = i;
				else
					break;
			}
//			System.out.println("now " + node1 + " is " + dp_parent[node1][exp]);
//			System.out.println("now " + node2 + " is " + dp_parent[node2][exp]);
			node1 = dp_parent[node1][exp];
			node2 = dp_parent[node2][exp];
		}
		anc = node1;
		return (anc);
	}
	
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			dp_parent = new int [n + 1][max_depth];
			depth = new int[n + 1];
			g = new ArrayList[n + 1];
			q = new LinkedList<>();
			ArrayList<Integer> visit_order = new ArrayList<>();
			//init
			for (int i = 0; i < n + 1; i++) {
				g[i] = new ArrayList<>();
				depth[i] = -1;
				for (int j = 0; j < max_depth; j++) {
					dp_parent[i][j] = -1;
				}
			}
			st = new StringTokenizer(br.readLine()," ");
			for (int i = 2; i < n + 1; i++) {
				int p = Integer.parseInt(st.nextToken());
				int node_num = i;
				g[p].add(node_num);
			}

			//sort child
			for (int i = 0; i < n + 1; i++) {
				g[i].sort(Comparator.naturalOrder());
			}

			//root
			depth[1] = 0;
			dp_parent[1][0] = 0;
			visit_order.add(1);
			for (int i = 0; i < g[1].size(); i++) {
				int child = g[1].get(i);
				int cur_height = 1;
				int [] node = new int[3];
				node[0] = child;//child
				node[1] = cur_height;//height
				node[2] = 1;//parent
				q.add(node);
			}

			//bfs
			while (q.size() != 0){
				int []node = q.poll();
				int cur_node = node[0];
				int cur_height = node[1];
				depth[cur_node] = cur_height;
				set_anc(node);
				visit_order.add(cur_node);
				for (int i = 0; i < g[cur_node].size(); i++) {
					int []next = new int[3];
					int next_node = g[cur_node].get(i);
					int next_height = cur_height + 1;
					next[0] = next_node;
					next[1] = next_height;
					next[2] = cur_node;
					q.add(next);
				}
			}

			long sol = 0;
			int start = 1;
			for (int i = 0; i < visit_order.size(); i++) {
				int to_node = visit_order.get(i);
//				System.out.println("finding lca of u, v : " +start+ ", "+ to_node);
				int lca = find_common_anc(start, to_node);
//				System.out.println("their lca is " + lca);
				int dis1 = get_distance(lca, start);
				int dis2 = get_distance(lca, to_node);
				sol+= dis1;
				sol+= dis2;
				start = to_node;
			}
			System.out.print("#" + (t_i + 1) + " " + sol + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

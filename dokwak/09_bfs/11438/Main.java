import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int []depth;
	static int max_depth = 21;
	static int [][]dp_parent;
	static ArrayList<Integer> []g;
	static boolean t = true;
	static boolean f = false;
	public static int find_LCA(int u, int v){
//		System.out.println("finding LCA of " + u + ", " + v);
		int anc = -1;
		//make v deeper depth node
		if (depth[u] > depth[v]){
			int temp = u;
			u = v;
			v = temp;
		}
		int diff = depth[v] - depth[u];
		int exp = 0;
		//make same depth with binary jump up
		while (depth[u] < depth[v]){
			exp = 0;
			//jump up as high as we can.
			for (int i = 0; i < max_depth; i++) {
				if ((1 << i) <= diff)
					exp = i;
				else
					break;
			}
//			System.out.println("jumping from, to : " + v + ", " +dp_parent[v][exp]);
			//change the v to v's anc
			v = dp_parent[v][exp];
			diff = depth[v] - depth[u];
		}
		//same depth now. find same ance with binary jump up
		while (u != v){
			exp = 0;
			for (int i = 0; i < max_depth; i++) {
				if (dp_parent[u][i] != dp_parent[v][i])
					exp = i;
				else
					break;
			}
			u = dp_parent[u][exp];
			v = dp_parent[v][exp];
		}
		anc = u;
		return (anc);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		//init
		depth = new int[n + 1];
		dp_parent = new int[n + 1][max_depth];
		g = new ArrayList[n + 1];
		boolean [] visited = new boolean[n + 1];
		for (int i = 0; i < n + 1; i++) {
			depth[i] = -1;
			g[i] = new ArrayList<>();
			visited[i] = false;
			for (int j = 0; j < max_depth; j++) {
				dp_parent[i][j] = -1;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			g[u].add(v);
			g[v].add(u);
		}
		depth[1] = 0;
		dp_parent[1][0] = 0;
		visited[1] = t;
		Queue<int []> q = new LinkedList<>();
		//root
		for (int i = 0; i < g[1].size(); i++) {
			int []node = new int[3];	
			node[0] = 1;//parent
			node[1] = g[1].get(i);//child
			node[2] = 1;//cur depth
			q.add(node);
		}
		//bfs travel
		while (q.size() != 0){
			int []cur = q.poll();
			int cur_parent = cur[0];
			int cur_node = cur[1];
			int cur_depth = cur[2];
			if (visited[cur_node] == t)
				continue;
			visited[cur_node] = t;
			dp_parent[cur_node][0] = cur_parent;
			for (int i = 1; i < max_depth; i++) {
				int up_depth = 1 << i;
				if (cur_depth - up_depth < 0)
					break;
				int half_parent = dp_parent[cur_node][i - 1];
				dp_parent[cur_node][i] = dp_parent[half_parent][i - 1];
			}
			depth[cur_node] = cur_depth;
			for (int i = 0; i < g[cur_node].size(); i++) {
				int next_node = g[cur_node].get(i);
				if (visited[next_node] == t)
					continue;
				int next_depth = cur_depth + 1;
				int []next = new int[3];
				next[0] = cur_node;
				next[1] = next_node;
				next[2] = next_depth;
				q.add(next);
			}
		}
		//query input
		st = new StringTokenizer(br.readLine()," ");
		int query = Integer.parseInt(st.nextToken());
		for (int i = 0; i < query; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int lca = find_LCA(u, v);
//			System.out.println("lca : " + lca);
			sb.append(lca + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

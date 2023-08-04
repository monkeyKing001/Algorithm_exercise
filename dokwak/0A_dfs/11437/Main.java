import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[] parent;
	static int[] depth;
	static ArrayList<Integer> [] g;

	public static int get_LCA(int u, int v){
		int anc = -1;
		if (depth[u] != depth[v]){
			if (depth[u] > depth[v])
			{
				int temp = u;
				u = v;
				v = temp;
			}
			while (depth[u] != depth[v]){
				v = parent[v];
			}
		}
		//now same depth
		while (u != v){
			u = parent[u];
			v = parent[v];
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
		parent = new int[n + 1];
		depth = new int[n + 1];
		g = new ArrayList[n + 1];
		boolean []visited = new boolean[n + 1];
		//init
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
			parent[i] = -1;
			depth[i] = -1;
			visited[i] = false;
		}
		parent[1] = 0;
		depth[1] = 0;
		visited[1] = true;
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int p = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			g[p].add(c);
			g[c].add(p);
		}
		Queue <int []> q = new LinkedList<>();
		for (int i = 0; i < g[1].size(); i++) {
			int []node = new int[3];
			int c = g[1].get(i);
			node[0] = c;//child
			node[1] = 1;//depth
			node[2] = 1;//parent
			q.add(node);
		}
		while (q.size() != 0){
			int []cur_node = q.poll();
			int cur = cur_node[0];
			int cur_depth = cur_node[1];
			int p = cur_node[2];
			if (visited[cur] == true)
				continue;
			parent[cur] = p;
			depth[cur] = cur_depth;
			visited[cur] = true;
			for (int i = 0; i < g[cur].size(); i++) {
				int next_child = g[cur].get(i);
				if (visited[next_child] == true)
					continue;
				int next_depth = cur_depth + 1;
				int []next_node = new int[3];
				next_node[0] = next_child;
				next_node[1] = next_depth;
				next_node[2] = cur;
				q.add(next_node);
			}
		}
		st = new StringTokenizer(br.readLine()," ");
		int query = Integer.parseInt(st.nextToken());
		for (int i = 0; i < query; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int lca = get_LCA(u, v);
			sb.append(lca + "\n");
		}
//		for (int i = 1; i < n + 1; i++) {
//			System.out.println("node, depth : " + i + ", " + depth[i]);
//		}
//		System.out.println();
//		for (int i = 1; i < n + 1; i++) {
//			System.out.println("node, parent : " + i + ", " + parent[i]);
//		}

		//travel bfs or dfs
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int p[];
	static int mst_cost;

	public static int find(int u){
		if (p[u] == -1)
			return u;
		p[u] = find(p[u]);
		return (p[u]);
	}

	public static void union(int u, int v){
		int u_p = find(u);
		int v_p = find(v);
		if (u_p == v_p)
			return;
		if (u_p > v_p){
			int temp = u_p;
			u_p = v_p;
			v_p = temp;
		}
		p[v_p] = u_p; 
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ArrayList<int[]> adj_list[] = new ArrayList[n + 1];
		ArrayList<int[]> edges = new ArrayList<>();
		boolean[] mst = new boolean[m];
		PriorityQueue<int[]> mst_pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int []e1, int[]e2){
				return (Integer.compare(e1[3], e2[3]));
			}
		});
		p = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
			p[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			int []info_u = new int[4];
			int []info_v = new int[4];
			info_u[0] = i;
			info_u[1] = u;
			info_u[2] = v;
			info_u[3] = cost;
			info_v[0] = i;
			info_v[1] = v;
			info_v[2] = u;
			info_v[3] = cost;
			adj_list[u].add(info_u);
			adj_list[v].add(info_v);
			edges.add(info_u);
			mst_pq.add(info_u);
			mst[i] = false;
		}
		//find mst first
		mst_cost = 0;
		int mst_edge_num = 0;
		while (mst_pq.size() != 0){
			if (mst_edge_num == n -1)
				break;
			int cur_info[] = mst_pq.poll();
			int edge_i = cur_info[0];
			int u = cur_info[1];
			int v = cur_info[2];
			int cur_cost = cur_info[3];
			if (find(u) != find(v))
			{
				union(u, v);
				mst_cost += cur_cost;
//				System.out.println("mst in u, v : " +u +", "+v);
//				System.out.println("cost : " + mst_cost);
				mst[edge_i] = true;
				mst_edge_num++;
			}
		}
//		System.out.println("mst cost : " + mst_cost);
		for (int i = 0; i < edges.size(); i++) {
			int total_cost = 0;
			//init
			int connect[] = edges.get(i);
			int conn_u = connect[1];
			int conn_v = connect[2];
			if (mst[i] == true){
//				System.out.println("in mst edge! : " + i);
				total_cost = mst_cost;
				System.out.println(total_cost);
				continue;
			}
//			System.out.println("u, v connect start : " +conn_u+", "+conn_v);
			total_cost += connect[3];
			Set<Integer> mst_nodes = new HashSet<>();
			mst_nodes.add(conn_u);
			mst_nodes.add(conn_v);
			PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
				@Override
				public int compare(int []e1, int[]e2){
					return (Integer.compare(e1[3], e2[3]));
				}
			});
			for (int con_u = 0; con_u < adj_list[conn_u].size(); con_u++) {
				pq.add(adj_list[conn_u].get(con_u));
			}
			for (int con_v = 0; con_v < adj_list[conn_v].size(); con_v++) {
				pq.add(adj_list[conn_v].get(con_v));
			}
			while(mst_nodes.size() != n && pq.size() != 0){
				int cur_info[] = pq.poll();
				int edge_i = cur_info[0];
				int cur_u = cur_info[1];
				int cur_v = cur_info[2];
				int cur_cost = cur_info[3];
				if (mst_nodes.contains(cur_v) == false){
					mst_nodes.add(cur_v);
					total_cost += cur_cost;
					if (mst_nodes.size() == n)
						break;
					for (int next_edge = 0; next_edge < adj_list[cur_v].size(); next_edge++) {
						pq.add(adj_list[cur_v].get(next_edge));
					}
				}
			}
			System.out.println(total_cost);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

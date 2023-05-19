import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		PriorityQueue <int []> pq = new PriorityQueue<>(new Comparator<int []>(){
			@Override
			public int compare(int []e1, int []e2)
			{
				return (Integer.compare(e1[0], e2[0]));
			};

		});
		TreeSet <Integer> mst = new TreeSet<>();
		ArrayList<int []> []g = new ArrayList[n + 1];
		for (int i = 0; i < n+1; i++) {
			g[i] = new ArrayList<int []>();
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int [] vertual_edge = new int[3];
			int cost = Integer.parseInt(st.nextToken());
			vertual_edge[0] = cost;
			vertual_edge[1] = 0;
			vertual_edge[2] = i + 1;
			pq.add(vertual_edge);
			g[0].add(vertual_edge);
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1 = i + 1;
			for (int j = 0; j < n; j++) {
				int cost = Integer.parseInt(st.nextToken());
				int v2 = j + 1;
				int [] edge = new int [3];
				int [] edge2 = new int [3];
				edge[0] = cost;
				edge[1] = v1;
				edge[2] = v2;
				edge2[0] = cost;
				edge2[1] = v2;
				edge2[2] = v1;
				g[v1].add(edge);
				g[v2].add(edge2);
			}
		}
		int m = 3;
		int start = pq.peek()[2];
		int mst_cost = pq.peek()[0];
		mst.add(start);
		for (int i = 0; i < g[start].size(); i++) {
			int [] edge = g[start].get(i);
			pq.add(edge);
		}
		while (pq.size() != 0 && mst.size() != n)
		{
			int []edge_in_pq = pq.poll();
			int cur_v = edge_in_pq[1];
			int cost = edge_in_pq[0];
			int connected_v = edge_in_pq[2];
			if (mst.contains(connected_v))
				continue ;
//			System.out.println("from " + cur_v + " -> connected : " + connected_v);
//			System.out.println("adding cost " + cost);
			mst_cost += cost;
//			System.out.println("now mst cost " + mst_cost);
			mst.add(connected_v);
			for (int i = 0; i < g[connected_v].size(); i++) {
				int next_v = g[connected_v].get(i)[2];
				if (mst.contains(next_v))
					continue; 
				pq.add(g[connected_v].get(i));
			}
		}
		System.out.println(mst_cost);
		return ;
	}
}

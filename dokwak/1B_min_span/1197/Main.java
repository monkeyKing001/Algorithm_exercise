import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[][] edges;
	static int[] parent;

	public static int find_parent(int v)
	{
		if (parent[v] == 0)
			return (v);
		parent[v] = find_parent(parent[v]);
		return (parent[v]);
	}

	public static boolean is_same_group(int v1, int v2)
	{
		return (find_parent(v1) == find_parent(v2));
	}

	public static void merge_group (int v1, int v2)
	{
		int v1_g = find_parent(v1);
		int v2_g = find_parent(v2);
		if (v1_g == v2_g)
			return ;
		if (v1_g > v2_g)
		{
			int temp = v1_g;
			v1_g = v2_g;
			v2_g = temp;
		}
		parent[v2_g] = v1_g;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		edges = new int[m][3];
		parent = new int [n + 1];
		for (int i = 0; i < n + 1; i++) {
			parent[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int v1, v2, cost;
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());
			cost = Integer.parseInt(st.nextToken());
			edges[i][0] = v1;
			edges[i][1] = v2;
			edges[i][2] = cost;
		}
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int [] e1, int [] e2){
				return (Integer.compare(e1[2], e2[2]));
			}
		});
		
		Arrays.sort(edges, new Comparator<int[]>()
				{
					@Override
					public int compare(int[] e1, int []e2)
					{
						return (Integer.compare(e1[2], e2[2]));
					}
				});
//		for (int i = 0; i < m; i++) {
//			System.out.println("edge[" + i + "] : from, to, cost : " + edges[i][0]+ ", "+ edges[i][1]+ ", "+ edges[i][2]);
//		}
		int mst_w = 0;
		int count = 0;

		for (int i = 0; i < m; i++) {
			int v1, v2, cost;
			v1 = edges[i][0];
			v2 = edges[i][1];
			cost = edges[i][2];
			if (is_same_group(v1, v2) == true)
				continue ;
			merge_group(v1, v2);
			count++;
			mst_w += cost;
			if (count == n - 1)
				break;
		}
		System.out.println(mst_w);
		return ;
	}
}

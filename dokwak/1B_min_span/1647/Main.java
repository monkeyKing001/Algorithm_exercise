import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
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
		if (find_parent(v1) == find_parent(v2))
			return (true);
		return (false);
	}
	
	public static void merge(int v1, int v2)
	{
		int v1_g = find_parent(v1);
		int v2_g = find_parent(v2);
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
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		parent = new int[100001];
		for (int i = 0; i < n + 1; i++) {
			parent[i] = 0;
		}
		int sol = 0;
		PriorityQueue <int []> pq = new PriorityQueue<>(new Comparator<int []>()
				{
					@Override
					public int compare(int []e1, int []e2)
					{
						return (Integer.compare(e1[2], e2[2]));
					}
				});
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			int []e = new int[3];
			e[0] = v1;
			e[1] = v2;
			e[2] = cost;
			pq.add(e);
		}
		int count = 0;
		while (pq.size() != 0 && count != n - 2)
		{
			int v1 = pq.peek()[0];
			int v2 = pq.peek()[1];
			int cost = pq.peek()[2];
			pq.poll();
			if (!is_same_group(v1, v2))
			{
				merge(v1, v2);
				sol += cost;
				count++;
//				System.out.println("now same group : "  + v1 + ", " + v2);
//				System.out.println("total_cost : " + sol);
//				System.out.println("max bridge is now " + max_bridge);
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



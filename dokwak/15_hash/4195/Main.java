import java.util.*;
import java.io.*;

public class Main{
	static int[] parent;
	static int[] size;
	
	public static int find(int v)
	{
		if (parent[v] == 0)
			return (v);
		parent[v] = find(parent[v]);
		return (parent[v]);
	}
	
	public static void union(int v1, int v2)
	{
		int v1_g = find(v1);
		int v2_g = find(v2);
		if (v1_g == v2_g)
			return ;
		if (v1_g > v2_g)
		{
			int temp = v1_g;
			v1_g = v2_g;
			v2_g = temp;
		}
		parent[v2_g] = v1_g;
		size[v1_g] += size[v2_g];
	}
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			parent = new int[200001];
			size = new int[200001];
			for (int i = 0; i < 200001; i++) {
				size[i] = 1;
			}
			Map<String, Integer> map = new HashMap();
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine()," ");
				String name1 = st.nextToken();
				String name2 = st.nextToken();
				int a = -1;
				int b = -1;
				if (map.containsKey(name1))
					a = map.get(name1);
				else {
					map.put(name1, map.size() + 1);
					a = map.get(name1);
				}
				if (map.containsKey(name2))
					b = map.get(name2);
				else {
					map.put(name2, map.size() + 1);
					b = map.get(name2);
				}
				union(a, b);
				int findA = find(a);
				System.out.println(size[findA]);
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

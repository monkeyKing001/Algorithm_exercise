import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[] parent;
	
	public static int find(int v)
	{
		if (parent[v] == -1)
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
		parent = new int [n + 1];
		for (int i = 0; i < n + 1; i++) {
			parent[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int cmd = Integer.parseInt(st.nextToken());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			if (cmd == 0)
				union(u, v);
			else{
				if (find(u) == find(v))
					sb.append("YES\n");
				else
					sb.append("NO\n");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



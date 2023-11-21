import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int parent[];

	static int find(int u){
		if (parent[u] == 0)
			return u;
		parent[u] = find(parent[u]);
		return(parent[u]);
	}

	static void union(int u, int v){
		int p_u = find(u);
		int p_v = find(v);
		if (p_u == p_v)
			return;
		if (p_u > p_v){
			int temp = p_u;
			p_u = p_v;
			p_v = temp;
		}
		parent[p_v] = p_u;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		parent = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
			parent[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n; j++) {
				int connected = Integer.parseInt(st.nextToken());
				if (connected == 0)
					continue;
				int u = i + 1;
				int v = j + 1;
//				System.out.println("u , v : " +u +","+v);
				union(u, v);
			}
		}
//		for (int i = 1; i < n + 1; i++) {
//			System.out.print(parent[i] + " ");
//		}
//		System.out.println();
		st = new StringTokenizer(br.readLine()," ");
		int cur = Integer.parseInt(st.nextToken());
		for (int i = 0; i < m - 1; i++) {
			int to = Integer.parseInt(st.nextToken());
//			System.out.println("from, to : " + cur+", "+ to);
			if (find(cur) != find(to))
			{
				System.out.println("NO");
				return;
			}
			cur = to;
		}
		System.out.println("YES");
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

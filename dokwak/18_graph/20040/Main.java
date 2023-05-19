import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int []parent;
	public static int find_parent(int v1)
	{
		if (parent[v1] == -1)
			return (v1);
		return (parent[v1] = find_parent(parent[v1]));
	}
	public static boolean same_group(int v1, int v2)
	{
		if (find_parent(v1) == find_parent(v2))
			return (true);
		else
			return (false);
	}
	public static void merge_group(int v1, int v2)
	{
		int g1 = find_parent(v1);
		int g2 = find_parent(v2);
		if (g1 > g2)
		{
			int temp = g1;
			g1 = g2;
			g2 = temp;
		}
		parent[g2] = g1;
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
		//init
		parent = new int[n + 1];
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			if (same_group(v1, v2) == true)
			{
				System.out.println(i + 1);
				return ;
			}
			else
				merge_group(v1, v2);
		}
		System.out.println(0);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int []p = new int [1001];

	public static int find_parent(int v)
	{
		if (p[v] == 0)
			return (v);
		p[v] = find_parent(p[v]);
		return (p[v]);
	}

	public static boolean is_same_parent(int v1, int v2)
	{
		return (find_parent(v1) == find_parent(v2));
	}

	public static void merge_group(int v1, int v2)
	{
		int g1 = find_parent(v1);
		int g2 = find_parent(v2);
		if (g2 < g1)
		{
			int temp = g1;
			g1 = g2;
			g2 = temp;
		}
		p[g2] = g1;
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		TreeSet<Integer> elm = new TreeSet<>();

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n + 1; i++) {
			p[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1, v2;
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());
			if (!is_same_parent(v1, v2))
				merge_group(v1, v2);
		}
		int sol = 0;
		for (int i = 1; i < n + 1; i++) {
			if (find_parent(i) == i)
				sol++;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

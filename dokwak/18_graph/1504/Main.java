//start 21:21
import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
//		int []visit_to_cost_from_start = new int[n + 1];
//		int []visit_to_cost_from_v1 = new int[n + 1];
//		int []visit_to_cost_from_v2 = new int[n + 1];
		int [][]g = new int[n + 1][n + 1];
//		PriorityQueue<int []> pq = new PriorityQueue<>(new Comparator<int []>()
//				{
//					@Override
//					public int compare(int []e1, int []e2)
//					{
//						return (Integer.compare(e1[2], e2[2]));
//					}
//				});
		int inf = 200000000;
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				g[i][j] = inf;
				if (i == j)
					g[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1, v2, cost;
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());
			cost = Integer.parseInt(st.nextToken());
			g[v1][v2] = Integer.min(cost, g[v1][v2]);
			g[v2][v1] = Integer.min(cost, g[v2][v1]);
		}
		for (int bridge = 1; bridge < n + 1; bridge++) {
			for (int start = 1; start < n + 1; start++) {
				for (int end = 1; end < n + 1; end++) {
					if (g[start][end] > g[start][bridge] + g[bridge][end])
					{
						g[start][end] = g[start][bridge] + g[bridge][end];
						g[end][start] = g[start][bridge] + g[bridge][end];
//						System.out.println("with bridge " + bridge);
//						System.out.println("new shortest path! from " + start +" to " + end + ": " + g[start][end]);
					}
				}
			}
		}
		st = new StringTokenizer(br.readLine(), " ");
		int v1, v2;
		v1 = Integer.parseInt(st.nextToken());
		v2 = Integer.parseInt(st.nextToken());
//		System.out.println(g[1][v1]);
//		System.out.println(g[v1][v2]);
//		System.out.println(g[v2][n]);
		long sol = 0;;
		if (g[1][v2] == inf || g[1][v2] == inf || g[v2][n] == inf || g[1][n] == inf)
		{
			System.out.println(-1);
			return ;
		}
		sol = Integer.min(g[1][v1]+ g[v1][v2] + g[v2][n], g[1][v2] + g[v2][v1] + g[v1][n]);
		System.out.println(sol);
//		bw.write(sb.toString());
//		bw.flush();
		return ;
	}
}



//start 4.21 13:48
//end 4.21 14:18
import java.util.*;
import java.io.*;

public class Main{
	static int n, m, w;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T;
		int inf = 10000000;
		T = Integer.parseInt(st.nextToken());
		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			int [][] g = new int[n+1][n+1];
			for (int i = 0; i < n + 1; i++) {
				for (int j = 0; j < n + 1; j++) {
					g[i][j] = inf;
					if (i == j)
						g[i][j] = 0;
				}
			}
			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int u, v, cost;
				u = Integer.parseInt(st.nextToken());
				v = Integer.parseInt(st.nextToken());
				cost = Integer.parseInt(st.nextToken());
				g[u][v] = Integer.min(cost, g[u][v]);
				g[v][u] = Integer.min(cost, g[v][u]);
			}
			for (int i = 0; i < w; i++) {
				st = new StringTokenizer(br.readLine());
				int u, v, cost;
				u = Integer.parseInt(st.nextToken());
				v = Integer.parseInt(st.nextToken());
				cost = Integer.parseInt(st.nextToken());
				g[u][v] = -cost;
			}
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1; j++) {
					for (int k = 1; k < n + 1; k++) {
						g[j][k] = Integer.min(g[j][i] + g[i][k], g[j][k]);
					}
				}
			}
			for (int i = 1; i < n + 1; i++) {
				if (g[i][i] < 0)
				{
					sb.append("YES\n");
					break ;
				}
				if (i == n)
					sb.append("NO\n");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

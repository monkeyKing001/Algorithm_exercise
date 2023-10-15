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
		int g[][] = new int [n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
			g[i][j] = 1000001;
			}
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken()) - 1;
			int v = Integer.parseInt(st.nextToken()) - 1;
			g[u][v] = 1;
			g[v][u] = 1;
		}
		for (int bridge = 0; bridge < n; bridge++) {
			for (int start = 0; start < n; start++) {
				for (int end = 0; end < n; end++) {
					g[start][end] = Integer.min(g[start][end], g[start][bridge] + g[bridge][end]);
					
				}
			}
		}
		int kevin_bacon = -1;
		int min_bacon_num = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			int temp_bacon_num = 0;
			for (int j = 0; j < n; j++) {
				if (i != j){
					temp_bacon_num += g[i][j];
				}
			}
			if (min_bacon_num > temp_bacon_num){
				min_bacon_num = temp_bacon_num;
				kevin_bacon = i + 1;
			}
		}
		System.out.println(kevin_bacon);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



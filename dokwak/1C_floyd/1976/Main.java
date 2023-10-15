import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int max = 8000001;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int g[][] = new int [n][n];
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n; j++) {
				int num = Integer.parseInt(st.nextToken());
				if (num == 0){
					g[i][j] = max; 
				}
				else{
					g[i][j] = 1;
				}
			}
		}
		//floyd
		for (int bridge = 0; bridge < n; bridge++) {
			for (int start = 0; start < n; start++) {
				for (int end = 0; end < n; end++) {
					g[start][end] = Integer.min(g[start][end], g[start][bridge] + g[bridge][end]);
				}
			}
		}
		st = new StringTokenizer(br.readLine()," ");
		int path[] = new int [m];
		for (int i = 0; i < m; i++) {
			int u = Integer.parseInt(st.nextToken());
			path[i] = u;
		}
		if (m == 1){
			System.out.println("YES");
			return;
		}
		for (int i = 0; i < m - 1; i++) {
			int start = path[i] - 1;
			int end = path[i + 1] - 1;
			if (start != end && g[start][end] == max){
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

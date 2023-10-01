import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int q;
	static int root;
	static ArrayList<Integer> adj_list[];
	static int dp[][];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());
		root = m;
		adj_list = new ArrayList[n + 1];
		dp = new int[n + 1][2];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			adj_list[u].add(v);
			adj_list[v].add(u);
		}
		for (int q_i = 0; q_i < q; q_i++) {
			st = new StringTokenizer(br.readLine()," ");
			int cur_root = Integer.parseInt(st.nextToken());
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



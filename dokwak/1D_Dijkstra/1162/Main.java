import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int cost[];
	static int path[][];
	static ArrayList<int[]> g[];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		g = new ArrayList[n + 1];
		path = new int [n + 1][n + 1];
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				path[i][j] = -1;
			}
		}
		cost = new int[n + 1];
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			public int compare(int []e1, int e2[]){
				return (Integer.compare(e1[1], e2[1]));
			}
		});
		for (int i = 0; i < n + 1; i++) {
			cost[i] = Integer.MAX_VALUE;
			g[i] = new ArrayList<>();
		}
		cost[1] = 0;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			int []u_info = new int [2];
			int []v_info = new int [2];
			u_info[0] = v;
			u_info[1] = cost;
			g[u].add(u_info);
			v_info[0] = u;
			v_info[1] = cost;
			g[v].add(v_info);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



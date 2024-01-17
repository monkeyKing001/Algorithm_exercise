import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static boolean visited[];
	static int totalIndegree[];
	static ArrayList<Integer>g[];

	public static void bfs(int start){
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		visited[start] = true;
		while (!q.isEmpty()){
			int cur = q.poll();
			totalIndegree[cur]++;
			for (int next_i = 0; next_i < g[cur].size(); next_i++) {
				int next = g[cur].get(next_i);
				if (!visited[next]){
					q.add(next);
					visited[next] = true;
				}
			}
		}
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
		totalIndegree = new int[n + 1];
		int maxTotalIndegree = 0;
		g = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			g[start].add(end);
		}
		for (int i = 1; i < n + 1; i++) {
			visited = new boolean[n + 1];
			int start = i;
			bfs(start);
		}
		maxTotalIndegree = 0;
		for (int i = 1; i < n + 1; i++) {
			maxTotalIndegree = Integer.max(maxTotalIndegree, totalIndegree[i]);
		}
		for (int i = 1; i < n + 1; i++) {
			if (totalIndegree[i] == maxTotalIndegree){
				sb.append(Integer.toString(i) + " ");
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



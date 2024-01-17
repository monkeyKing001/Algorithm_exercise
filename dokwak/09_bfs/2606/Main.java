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
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		ArrayList<Integer> g[] =  new ArrayList[n + 1];
		boolean visited[] = new boolean[n + 1];
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
		}
		Queue<Integer> q = new LinkedList<>();
		int count = 0;
		q.add(1);
		visited[1] = true;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			g[start].add(end);
			g[end].add(start);
		}

		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int to_i = 0; to_i < g[cur].size(); to_i++) {
				int next = g[cur].get(to_i);
				if (!visited[next]){
					q.add(next);
					visited[next] = true;
					count++;
				}
			}
		}
		System.out.println(count);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> g[];
	static int visited[] = new int [1000001];
	static int visitedNodeSum = 0;
	static int visitedEdgeSum = 0;
	static int indegree[] = new int[1000001];
	static int outdegree[] = new int[1000001];
	static int generator= -1;
	static int donut = 0;
	static int eight = 0;
	static int straight = 0;
	static boolean comp = true;

	public static void rec(int cur){
		if (g[cur].size() == 0) {
			straight++;
		}
		else if (g[cur].size() > 1 && comp == true) {
			eight++;
			comp = false;
		}
		else if (g[cur].size() == 1 && visited[g[cur].get(0)] == 1 && comp == true) {
			donut++;
		}
		if (visited[cur] == 1)
			return;
		visited[cur] = 1;
		for (int i = 0; i < g[cur].size(); i++){
			int next = g[cur].get(i);
			rec(next);
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
		g = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			g[u].add(v);
			outdegree[u]++;
			indegree[v]++;
		}
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0 && outdegree[i] != 0)
			{
				generator = i;
				break;
			}
		}
		for (int i = 0; i < g[generator].size(); i++) {
			int start = g[generator].get(i);
			comp = true;
			rec(start);
		}
		int answer[] = {generator, donut, straight, eight};
		for (int i = 0; i < 4; i++) {
			System.out.print(answer[i] + " ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



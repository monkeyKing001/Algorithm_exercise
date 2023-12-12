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
		int dp[][] = new int [n + 1][n + 1];
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
			@Override
			public int compare(int [] e1, int [] e2){
				return (Integer.compare(e1[2], e2[2]));
			}
		});
		ArrayList<int[]> g[] = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			g[i] = new ArrayList<>();
			for (int j = 0; j < n + 1 ; j++){
				dp[i][j] = 10000001;
				if (i == j)
					dp[i][j] = 0;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			int e1[] = new int [3];
			int e2[] = new int [3];
			e1[0] = u;
			e1[1] = v;
			e1[2] = cost;
			g[u].add(e1);
			e2[0] = v;
			e2[1] = u;
			e2[2] = cost;
			g[v].add(e2);
			dp[u][v] = cost;
			dp[v][u] = cost;
		}
		for (int i = 1; i < n + 1; i++) {
			int start = i;
			for (int startAdj = 0; startAdj < g[start].size(); startAdj++) {
				pq.add(g[start].get(startAdj));
			}
			while (pq.size() != 0){
				int curInfo[] = pq.poll();
				int v = curInfo[1];
				int curCost = dp[start][v];
				for (int gAdj = 0; gAdj < g[v].size(); gAdj++) {
					int nextV = g[v].get(gAdj)[1];
					int nextCost = g[v].get(gAdj)[2];
					if (dp[start][nextV] > curCost + nextCost){
						int next[] = new int[3];
						next[0] = start;
						next[1] = nextV;
						next[0] = curCost + nextCost;
						dp[start][nextV] = curCost + nextCost;
						pq.add(next);
					}
				}
			}
		}
//		for (int i = 1; i < n + 1; i++) {
//			for (int j = 1; j < n + 1 ; j++){
//				System.out.print(dp[i][j]);
//			}
//			System.out.println();
//		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			sb.append(dp[u][v]);
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



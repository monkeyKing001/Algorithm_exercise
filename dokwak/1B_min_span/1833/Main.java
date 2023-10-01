import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int p[];
	public static int find(int v){
//		System.out.println("FIND : " + v);
		if (p[v] == -1)
			return v;
		p[v] = find(p[v]);
//		System.out.println("v, p[v] : " + v+ ", "+ p[v]);
		return (p[v]);
	}

	public static void union(int u, int v){
//		System.out.println("UNION");
		int p_u = find(u);
		int p_v = find(v);
		if (p_v == p_u)
			return;
		if (p_v < p_u){
			int temp = p_u;
			p_u = p_v;
			p_v = temp;
		}
		p[p_v] = p_u;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		p = new int [n + 1];
		for (int i = 0; i < n + 1; i++) {
			p[i] = -1;
		}
		PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comparator<int[]>(
				){
				@Override
				public int compare(int e1[], int e2[]){
					return (Integer.compare(e1[2], e2[2]));
				}
		});
		//init
		int total_edge = 0;
		int total_cost = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n; j++) {
				int cost = Integer.parseInt(st.nextToken());
				if (i >= j)
					continue;
//				System.out.println("checking u, v : " +i+", "+j);
				//already connected
				if (cost < 0)
				{
					total_cost += Math.abs(cost);
					union(i, j);
				}
				else{
					int edge[] = new int [3];
					edge[0] = i;
					edge[1] = j;
					edge[2] = cost;
					pq.add(edge);
				}
			}
		}
		while (pq.size() != 0){
			int cur_info[] = pq.poll();
			int u = cur_info[0];
			int v = cur_info[1];
			int cost = cur_info[2];
			if (find(u) != find(v)){
				union(u, v);
				sb.append((u + 1) + " " + (v + 1) + "\n");
				total_cost += cost;
				total_edge++;
			}
		}
		bw.write(total_cost + " " + total_edge + "\n");
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



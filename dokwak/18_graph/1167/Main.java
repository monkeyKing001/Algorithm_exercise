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
		ArrayList<int []> []adj_list = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			if (v == -1)
				continue ;
			int cost;
			while (v != -1)
			{
				cost = Integer.parseInt(st.nextToken());
				int [] edge = new int[3];
				edge[0] = u;
				edge[1] = v;
				edge[2] = cost;
				adj_list[u].add(edge);
				v = Integer.parseInt(st.nextToken());
			}
		}
		Queue<int[]> q = new LinkedList<>();
		int start = 1;
		int total_step = 0;
		for (int i = 0; i < adj_list[start].size(); i++) {
			int connected_v = adj_list[start].get(i)[1];
			int step = adj_list[start].get(i)[2];
			int [] edge = new int [3];
			edge[0] = 1;
			edge[1] = connected_v;
			edge[2] = step;
			q.add(edge);
		}
		while (q.size() != 0)
		{
			int current_v = q.peek()[0];
			int connected_v = q.peek()[1];
			int acc_step = q.peek()[2];
			q.poll();
			if (adj_list[connected_v].size() == 1 && total_step < acc_step)
			{
				total_step = acc_step;
				start = connected_v;
				continue ; 
			}
			for (int i = 0; i < adj_list[connected_v].size(); i++) {
				int next_v, next_step;
				next_v = adj_list[connected_v].get(i)[1];
				next_step = adj_list[connected_v].get(i)[2];
				if (next_v == current_v)
					continue ;
				int [] next_edge = new int[3];
				next_edge[0] = connected_v;
				next_edge[1] = next_v;
				next_edge[2] = acc_step + next_step;
				q.add(next_edge);
			}
		}
		for (int i = 0; i < adj_list[start].size(); i++) {
			int connected_v = adj_list[start].get(i)[1];
			int step = adj_list[start].get(i)[2];
			int [] edge = new int [3];
			edge[0] = start;
			edge[1] = connected_v;
			edge[2] = step;
			q.add(edge);
		}
		total_step = 0;
//		System.out.print("longest path : " + start);
		while (q.size() != 0)
		{
			int current_v = q.peek()[0];
			int connected_v = q.peek()[1];
			int acc_step = q.peek()[2];
			q.poll();
			if (adj_list[connected_v].size() == 1 && total_step < acc_step)
			{
				total_step = acc_step;
				start = connected_v;
//				System.out.println(" to " + start + " with cost " + acc_step);
				continue ; 
			}
			for (int i = 0; i < adj_list[connected_v].size(); i++) {
				int next_v, next_step;
				next_v = adj_list[connected_v].get(i)[1];
				next_step = adj_list[connected_v].get(i)[2];
				if (next_v == current_v)
					continue ;
				int [] next_edge = new int[3];
				next_edge[0] = connected_v;
				next_edge[1] = next_v;
				next_edge[2] = acc_step + next_step;
				q.add(next_edge);
			}
		}
		System.out.println(total_step);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



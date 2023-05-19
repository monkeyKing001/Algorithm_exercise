import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<int[]> adj_list[] = new ArrayList[10001];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
		}
		String buf = br.readLine();
		while (buf != null)
		{
			st = new StringTokenizer(buf, " ");
			int p, c, cost_to_visit;
			int [] edge1 = new int[3];
			int [] edge2 = new int[3];
			p = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			cost_to_visit = Integer.parseInt(st.nextToken());
			edge1[0] = p;
			edge1[1] = c;
			edge1[2] = cost_to_visit;
			edge2[0] = c;
			edge2[1] = p;
			edge2[2] = cost_to_visit;
			adj_list[p].add(edge1);
			adj_list[c].add(edge2);
			buf = br.readLine();
		}
		int start = 1;
		int total_step = 0;
		Queue <int[]> q = new LinkedList<>();
		for (int i = 0; i < adj_list[start].size(); i++) {
			int [] start_point = new int[3];
			int connected_point = adj_list[start].get(i)[1];
			start_point[0] = start;
			start_point[1] = connected_point;
			start_point[2] = adj_list[start].get(i)[2];
			q.add(start_point);
		}
		while (q.size() != 0)
		{
			int current_point = q.peek()[0];
			int connected_point = q.peek()[1];
			int acc_step = q.peek()[2];
			q.poll();
			if (adj_list[connected_point].size() == 1 && acc_step > total_step)
			{
				start = connected_point;
				total_step = acc_step;
			}
			for (int i = 0; i < adj_list[connected_point].size(); i++) {
				int next_point = adj_list[connected_point].get(i)[1];
				int next_step = adj_list[connected_point].get(i)[2];
				if (next_point == current_point)
					continue ;
				int [] next = new int[3];
				next[0] = connected_point;
				next[1] = next_point;
				next[2] = acc_step + next_step;
				q.add(next);
			}
		}
		int sol = 0;
		total_step = 0;
		for (int i = 0; i < adj_list[start].size(); i++) {
			int [] start_point = new int[3];
			int connected_point = adj_list[start].get(i)[1];
			start_point[0] = start;
			start_point[1] = connected_point;
			start_point[2] = adj_list[start].get(i)[2];
			q.add(start_point);
		}
		while (q.size() != 0)
		{
			int current_point = q.peek()[0];
			int connected_point = q.peek()[1];
			int acc_step = q.peek()[2];
			q.poll();
			if (adj_list[connected_point].size() == 1 && acc_step > total_step)
			{
				start = connected_point;
				total_step = acc_step;
			}
			for (int i = 0; i < adj_list[connected_point].size(); i++) {
				int next_point = adj_list[connected_point].get(i)[1];
				int next_step = adj_list[connected_point].get(i)[2];
				if (next_point == current_point)
					continue ;
				int [] next = new int[3];
				next[0] = connected_point;
				next[1] = next_point;
				next[2] = acc_step + next_step;
				q.add(next);
			}
		}
		System.out.println(total_step);
		return ;
	}
}

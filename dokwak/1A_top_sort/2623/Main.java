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
		ArrayList<Integer> sol = new ArrayList<>();
		Set<Integer> out_arr[] = new TreeSet[1001];
		Set<Integer> in_arr[] = new TreeSet[1001];
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		int [] outdegree = new int[1001];
		//input
		n = Integer.parseInt(st.nextToken());
		for (int i = 1; i < n + 1; i++) {
			out_arr[i] = new TreeSet<Integer>();
			in_arr[i] = new TreeSet<Integer>();
		}
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			int prev = -1;
			for (int j = 0; j < num; j++) {
				int u = Integer.parseInt(st.nextToken());
				if (prev != -1)
				{
					in_arr[prev].add(u);
					out_arr[u].add(prev);
				}
				prev = u;
			}
		}
		for (int i = 1; i < n + 1; i++) {
			if (out_arr[i].size() == 0)
				pq.add(i);
		}
		while (pq.size() != 0)
		{
			int cur_num = pq.poll();
			sol.add(cur_num);
			Iterator<Integer> it = in_arr[cur_num].iterator();
			while (it.hasNext())
			{
				int rm = it.next();
				out_arr[rm].remove(cur_num);
				//in_arr[cur_num].remove(rm); wronkcode.
				if (out_arr[rm].size() == 0)
					pq.add(rm);
			}
			in_arr[cur_num].clear();
		}
		if (pq.size() == 0 && sol.size() != n)
		{
			System.out.println("0");
			return ;
		}
		//print sol
		for (int i = 0; i < sol.size(); i++) {
			System.out.println(sol.get(i));
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



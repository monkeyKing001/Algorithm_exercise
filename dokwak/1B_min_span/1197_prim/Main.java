import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		TreeSet<Integer> set = new TreeSet<>();
		ArrayList<int[]> []arr = new ArrayList[n + 1];
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int []>() {
				@Override
				public int compare(int []e1, int []e2)
				{
					return (Integer.compare(e1[2], e2[2]));
				}
		});
		int start = 1;
		for (int i = 0; i < n+1; i++) {
			arr[i] = new ArrayList<int[]>();	
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int v1, v2, cost;
			v1 = Integer.parseInt(st.nextToken());
			v2 = Integer.parseInt(st.nextToken());
			cost = Integer.parseInt(st.nextToken());
			int []e1 = new int[3];
			int []e2 = new int[3];
			e1[0] = v1;
			e1[1] = v2;
			e1[2] = cost;
			e2[0] = v2;
			e2[1] = v1;
			e2[2] = cost;
			arr[v1].add(e1);
			arr[v2].add(e2);
			if (v1 == start)
				pq.add(e1);
		}
		int mst_w = 0;
		set.add(1);
		while (pq.size() != 0)
		{
			int cur_v, cost, connected_v;
			cur_v = pq.peek()[0];
			connected_v = pq.peek()[1];
			cost = pq.peek()[2];
			pq.poll();
			if (set.contains(connected_v))
				continue;
			set.add(connected_v);
			mst_w += cost;
			if (set.size() == n)
				break;
			for (int i = 0; i < arr[connected_v].size(); i++) {
				int next_v = arr[connected_v].get(i)[1];
				if (set.contains(next_v))
					continue ;
				pq.add(arr[connected_v].get(i));
			}
		}
		System.out.println(mst_w);
		return ;
	}
}

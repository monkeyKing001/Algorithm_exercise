import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static int find_next(int v, int s)
	{
		for (int i = 0; i < n; i++) {
			int temp = s >> i;
			if (temp % 2 == 1)
				return (i);
		}
		return (0);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int []>(){
			@Override
			public int compare(int []e1, int []e2)
			{
				return (Integer.compare(e1[2], e1[2]));
			}
		});
		n = Integer.parseInt(st.nextToken());
		int [][]mat = new int[n + 1][(1 << n) + 1];
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 1; j < n + 1; j++) {
				int cost = Integer.parseInt(st.nextToken());
				mat[i][j] = cost;
				int [] e = new int[3];
				e[0] = i;
				e[1] = j;
				e[2] = cost;
				if (cost == 0)
					e[2] = Integer.MAX_VALUE;
				pq.add(e);
			}
		}
		int start_v = pq.peek()[0];
		int to_v = pq.peek()[1];
		int cost = pq.peek()[2];
		pq.poll();
		while (pq.size() != 0)
		{
		}

		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



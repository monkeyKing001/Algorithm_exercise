import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int []arr = new int[100001];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		Queue <int[]> q = new LinkedList<>();
		for (int i = 0; i < 100001; i++) {
			arr[i] = -1;
		}
		arr[n] = 0;	
		int []pos = new int[2];
		pos[0] = n;
		pos[1] = 0;
		q.add(pos);
		while (q.size() != 0)
		{
			int cur = q.peek()[0];
			int step = arr[cur];
			if (cur == m)
			{
				System.out.println(step);
				return ;
			}
			q.poll();
			for (int i = 0; i < 3; i++) {
				int next_pos = 0;
				int next_step = 0;
				if (i == 0)
				{
					next_pos = cur * 2;
					next_step = step;
				}
				else if (i == 1)
				{
					next_pos = cur + 1;
					next_step = step + 1;
				}
				else if (i == 2)
				{
					next_pos = cur - 1;
					next_step = step + 1;
				}
				if ((next_pos < 100001 && next_pos > -1 && arr[next_pos] == -1) ||
						(next_pos < 100001 && next_pos > -1 && arr[next_pos] > next_step))
				{
					int [] next = new int[2];
					next[0] = next_pos;
					next[1] = next_step;
					arr[next_pos] = next_step;
					q.add(next);
				}
			}
		}
		return ;
	}
}

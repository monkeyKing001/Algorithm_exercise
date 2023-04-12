import java.util.*;
import java.io.*;

public class Main{
	static Long n, m;
	static long max_num = 1000000001L;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Long.parseLong(st.nextToken());
		m = Long.parseLong(st.nextToken());
		Queue <Long[]> q = new LinkedList<>();
		Long[] pos = new Long[2];
		pos[0] = n;
		pos[1] = 1L;
		q.add(pos);
		while (q.size() != 0)
		{
			Long cur_num = q.peek()[0];
			Long cur_step = q.peek()[1];
			if (cur_num == m)
			{
				System.out.println(cur_step);
				return ;
			}
			q.poll();
			for (int i = 0; i < 2; i++) {
				Long next_num;
				if (i == 0)
					next_num = (cur_num * 10) + 1;
				else
					next_num = cur_num * 2;
				if (next_num < max_num && next_num <= m)
				{
					Long [] next_pos = new Long[2];
					next_pos[0] = next_num;
					next_pos[1] = cur_step + 1;
					q.add(next_pos);
				}
			}
		}
		System.out.println(-1);
		return ;
	}
}

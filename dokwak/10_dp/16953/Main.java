import java.util.*;
import java.io.*;

public class Main{
	static long n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Long.parseLong(st.nextToken());
		m = Long.parseLong(st.nextToken());
		Queue <long[]> q = new LinkedList<>();
		long [] point = new long[2];
		point[0] = n;
		point[1] = 1;
		q.add(point);
		while (q.size() != 0)
		{
			long [] cur_point = q.poll();
			long cur_num = cur_point[0];
			long cur_step = cur_point[1];
			if (cur_num == m)
			{
				System.out.println(cur_step);
				return ;
			}
			for (int i = 0; i < 2; i++) {
				long next_num;
				long next_step = cur_step + 1;
				if (i == 0)
					next_num = cur_num * 2;
				else
					next_num = (cur_num * 10) + 1;
				if (next_num <= m)
				{
					long [] next_point = new long [2];
					next_point[0] = next_num;
					next_point[1] = next_step;
					q.add(next_point);
				}
			}
		}
		System.out.println(-1);
		return ;
	}
}

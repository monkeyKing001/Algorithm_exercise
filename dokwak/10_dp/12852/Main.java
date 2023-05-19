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
		int [][] dp = new int[1000001][2];
		for (int i = 0; i < 1000001; i++) {
			dp[i][0] = 1000001;
		}
		dp[1][0] = 0;
		dp[1][1] = 1;
		Queue<Integer> q = new LinkedList<>();
		q.add(1);
		while (q.size() != 0)
		{
			int cur = q.poll();
			int cur_step = dp[cur][0];
			for (int i = 0; i < 3; i++)
			{
				int next = cur + 1;
				if (i == 1)
					next = cur * 2;
				else if (i == 2)
					next = cur * 3;
				if (next <= n && dp[next][0] > cur_step + 1)
				{
					dp[next][0] = cur_step + 1;
					dp[next][1] = cur;
					q.add(next);
				}
			}
		}
		System.out.println(dp[n][0]);
		int index = n;
		System.out.print(index + " ");
		while (index != 1)
		{
			System.out.print(dp[index][1] + " ");
			index = dp[index][1];
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

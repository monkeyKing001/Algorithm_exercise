// start 10:36, 14, Apr
// end 11:14 1st try
import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int inf = 1000000000;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int [][] map = new int[n+1][m+1];
		int [][] dp_no_break = new int[n+1][m+1];
		int [][] dp_break = new int[n+1][m+1];
		//input_map
		for (int i = 1; i < n + 1; i++) {
			String line = br.readLine();
			for (int j = 1; j < m + 1; j++) {
				char c = line.charAt(j - 1);
				if (c == '0')
					map[i][j] = 0;
				else
					map[i][j] = inf;
			}
		}
		//init dp
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < m + 1; j++) {
				dp_no_break[i][j] = inf;
				dp_break[i][j] = inf;
			}
		}
		//bfs
		int []dr = {1, 0, -1, 0};
		int []dc = {0, 1, 0, -1};
		Queue <int []> q = new LinkedList<>();
		int [] start = {1, 1};
		dp_no_break[1][1] = 1;
		q.add(start);
		while (q.size() != 0 )
		{
			int []cur_cor = q.poll();
			int cur_r = cur_cor[0];
			int cur_c = cur_cor[1];
			int cur_step = dp_no_break[cur_r][cur_c];
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i];
				int next_c = cur_c + dc[i];
				int next_step = cur_step + 1;
				if (next_r > 0 
						&& next_r < n + 1 
						&& next_c > 0 
						&& next_c < m + 1 
						&& map[next_r][next_c] == 0)
				{
					if (dp_no_break[next_r][next_c] > next_step)
					{
						dp_no_break[next_r][next_c] = next_step;
						int [] next_cor = {next_r, next_c};
						q.add(next_cor);
					}
				}
			}
		}
		dp_break[1][1] = 1;
		q.add(start);
		while (q.size() != 0 )
		{
			int []cur_cor = q.poll();
			int cur_r = cur_cor[0];
			int cur_c = cur_cor[1];
			int cur_step = dp_break[cur_r][cur_c];
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i];
				int next_c = cur_c + dc[i];
				int next_step = cur_step + 1;
				if (next_r > 0 
						&& next_r < n + 1 
						&& next_c > 0 
						&& next_c < m + 1 
						&& ((map[next_r][next_c] == 0) || (map[next_r][next_c] != 0 && dp_no_break[cur_r][cur_c] != inf)))
				{
					if (map[next_r][next_c] == 0 && dp_break[next_r][next_c] > next_step)
					{
						int [] next_cor = {next_r, next_c};
						dp_break[next_r][next_c] = next_step;
						q.add(next_cor);
					}
					else if (map[next_r][next_c] == inf && dp_break[next_r][next_c] > dp_no_break[cur_r][cur_c] + 1)
					{
						int [] next_cor = {next_r, next_c};
						dp_break[next_r][next_c] = dp_no_break[cur_r][cur_c] + 1;
						q.add(next_cor);
					}
				}
			}
		}
		long sol = Integer.min(dp_break[n][m], dp_no_break[n][m]);
		if (sol == inf)
			sol = -1;
		System.out.println(sol);
//
//		bw.write(sb.toString());
//		bw.flush();
		return ;
	}
}

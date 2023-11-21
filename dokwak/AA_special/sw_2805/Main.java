import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {1, 0, -1, 0};
	static int dc[] = {0, 1, 0, -1};
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			int farm[][] = new int[n][n];
			int visited[][] = new int[n][n];
			for (int i = 0; i < n; i++) {
				String info = br.readLine().toString();
				for (int j = 0; j < n; j++) {
					farm[i][j] = info.charAt(j) - '0';
					visited[i][j] = 0;
				}
			}
			int sol = 0;
			int start_r = n / 2;
			int start_c = n / 2;
			int start[] = new int[2];
			start[0] = start_r;
			start[1] = start_c;
			Queue<int[]> q = new LinkedList<>();
			q.add(start);
			while (q.size() != 0){
				int cur[] = q.poll();
				int cur_r = cur[0];
				int cur_c = cur[1];
				if (visited[cur_r][cur_c] == 1)
					continue;
				visited[cur_r][cur_c] = 1;
				sol+= farm[cur_r][cur_c];
				for (int i = 0; i < 4; i++) {
					int next_r = cur_r + dr[i];
					int next_c = cur_c + dc[i];
					int dis = 0;
					dis += Math.abs(start_r - next_r) + Math.abs(start_c - next_c);
					if (next_r > -1 && next_r < n && next_c > -1 && next_c < n && dis <= (n / 2)){
						if (visited[next_r][next_c] == 1)
							continue;
						int []next = new int[2];
						next[0] = next_r;
						next[1] = next_c;
						q.add(next);
					}
				}
			}
			System.out.println("#" + (t_i + 1) +" " + sol);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

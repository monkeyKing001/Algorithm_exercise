import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[]dr = {-1, 0, 1, 0}; //U R D L
	static int[]dc = {0, 1, 0, -1};
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int [][] map = new int[1001][1001];
		int [][] visited = new int[1001][1001];
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		int sol = 0;
		int count = 0;
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < line.length(); j++) {
				map[i][j] = line.charAt(j);
			}
		}
		Queue <int []> q = new LinkedList<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int start_r = i;
				int start_c = j;
				if (visited[start_r][start_c] != 0)
					continue ;
				int []start = new int [2];
				start[0] = start_r;
				start[1] = start_c;
				count++;
				visited[start_r][start_c] = count;
				q.add(start);
				while (q.size() != 0)
				{
					int cur_r = q.peek()[0];
					int cur_c = q.peek()[1];
					q.poll();
					int next_r = cur_r + dr[0];
					int next_c = cur_c + dc[0];
					if (map[cur_r][cur_c] == 'R')
					{
						next_r = cur_r + dr[1];
						next_c = cur_c + dc[1];
					}
					else if (map[cur_r][cur_c] == 'D')
					{
						next_r = cur_r + dr[2];
						next_c = cur_c + dc[2];
					}
					else if (map[cur_r][cur_c] == 'L')
					{
						next_r = cur_r + dr[3];
						next_c = cur_c + dc[3];
					}
					if (visited[next_r][next_c] == 0)
					{
						int []next = new int[2];
						next[0] = next_r;
						next[1] = next_c;
						q.add(next);
						visited[next_r][next_c] = count;
					}
					else if (visited[next_r][next_c] == count)
					{
						sol++;
					}
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



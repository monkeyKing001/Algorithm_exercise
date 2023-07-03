import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[] dr = {0, 1, -1, 0};
	static int[] dc = {1, 0, 0, -1};
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int [][]map = new int [1001][1001];
		int [][]visited = new int [1001][1001];
		int []start = new int[2];
		Queue <int[]> q = new LinkedList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				visited[i][j] = 0;
				if (map[i][j] == 2){
					start[0] = i;
					start[1] = j;
				}
			}
		}
		visited[start[0]][start[1]] = 0;
		q.add(start);
		while (q.size() != 0 )
		{
			int []cur = q.poll();
			int cur_r = cur[0];
			int cur_c = cur[1];
			int cur_step = visited[cur_r][cur_c];
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i];
				int next_c = cur_c + dc[i];
				if (next_r > -1 && next_r < n && next_c > -1 && next_c < m && (visited[next_r][next_c] == 0 || visited[next_r][next_c] != 0 && visited[next_r][next_c] > cur_step + 1) && map[next_r][next_c] == 1)
				{
					visited[next_r][next_c] = cur_step + 1;
					int []next = new int [2];
					next[0] = next_r;
					next[1] = next_c;
					q.add(next);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0)
					sb.append("-1 ");
				else
					sb.append(visited[i][j] + " ");
			}
			sb.append("\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



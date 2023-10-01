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
		int map[][] = new int [n][m];
		int visited[][] = new int [n][m];
		int start_r = -1;
		int start_c = -1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				visited[i][j] = 0;
				if (map[i][j] == 2)
				{
					start_r = i;
					start_c = j;
				}
			}
		}
		Queue<int[]> q = new LinkedList();
		int [] start = new int [3];
		start[0] = start_r;
		start[1] = start_c;
		start[2] = 0;
		q.add(start);
		while (q.size() != 0){
			int cur[] = q.poll();
			int cur_r = cur[0];
			int cur_c = cur[1];
			int cur_cost = cur[2];
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i];
				int next_c = cur_c + dc[i];
				int next_cost = cur_cost + 1;
				if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m && map[next_r][next_c] == 1 && visited[next_r][next_c] == 0){
					visited[next_r][next_c] = next_cost;
					int []next_info = new int[3];
					next_info[0] = next_r;
					next_info[1] = next_c;
					next_info[2] = next_cost;
					q.add(next_info);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && map[i][j] == 1)
					System.out.print("-1 ");
				else
					System.out.print(visited[i][j] + " ");
			}
			System.out.println();
		}
		bw.write(sb.toString());
		bw.flush();
	}
}



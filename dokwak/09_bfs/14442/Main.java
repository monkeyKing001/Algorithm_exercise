import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int [] start = new int[4]; //r, c, chance, step
		start[0] = 0;//r
		start[1] = 0;//c
		start[2] = k;//last chance
		start[3] = 1;//step
		int map[][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length() ; j++){
				map[i][j] = str.charAt(j) - '0';
			}
		}
		boolean visited[][][] = new boolean[k + 1][n][m];
		Queue<int[]> q = new LinkedList<>();
		q.add(start);
		visited[k][0][0] = true;
		int sol = Integer.MIN_VALUE;
		while (q.size() != 0){
			int cur[] = q.poll();
			int cur_r = cur[0];
			int cur_c = cur[1];
			int cur_lastChance = cur[2];
			int cur_step = cur[3];
			if (cur_r == n - 1 && cur_c == m - 1){
				sol = cur_step;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i];
				int next_c = cur_c + dc[i];
				if (next_r < n && next_r > -1 && next_c < m && next_c >-1 && !visited[cur_lastChance][next_r][next_c]){
					int [] next_point = new int[4];
					next_point[0] = next_r;
					next_point[1] = next_c;
					next_point[2] = cur_lastChance;
					next_point[3] = cur_step + 1;
					if (map[next_r][next_c] == 0){
						visited[cur_lastChance][next_r][next_c] = true;
						q.add(next_point);
					}
					else if (cur_lastChance >= 1 && !visited[cur_lastChance - 1][next_r][next_c]){
						next_point[2] = cur_lastChance - 1;
						visited[cur_lastChance - 1][next_r][next_c] = true;
						q.add(next_point);
					}
				}
			}
		}
		sol = Integer.max(-1, sol);
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
	static int [][] map;
	static int [][] globalVisited;
	static int globalMaximum = 0;
	public static void bfs(int start_r, int start_c){
		int visited[][] = new int[n][m];
		Queue<int[]> q = new LinkedList<>();
		int start[] = new int[2];
		start[0] = start_r;
		start[1] = start_c;
		q.add(start);
		visited[start_r][start_c] = 1;
		int localMaximum = 0;
		while (q.size() != 0){
			int cur[] = q.poll();
			int cur_r = cur[0];
			int cur_c = cur[1];
			for (int d_i = 0; d_i < 4; d_i++) {
				int next_r = cur_r + dr[d_i];
				int next_c = cur_c + dc[d_i];
				if (next_r < n && next_r > -1 
						&& next_c < m && next_c >-1 
						&& visited[next_r][next_c] == 0 
						&& map[next_r][next_c] == 0){
					int [] next_point = new int[2];
					next_point[0] = next_r;
					next_point[1] = next_c;
					visited[next_r][next_c] = visited[cur_r][cur_c] + 1;
					localMaximum = Math.max(localMaximum, visited[next_r][next_c]);
					q.add(next_point);
				}
			}
		}
		globalMaximum = Math.max(globalMaximum, localMaximum);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		globalVisited = new int[n][m];
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = (str.charAt(j) == 'W') ? 1 : 0;
			}
		}
		globalMaximum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++) {
				if(map[i][j] == 0 && globalVisited[i][j] == 0) {
					bfs(i, j);
					globalVisited[i][j] = 1;
				}
			}
		}
		System.out.println(globalMaximum - 1);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



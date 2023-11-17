import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
	public static void print(int[][] dp){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(dp[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
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
		Queue<int[]> q = new LinkedList<>();
		Queue<int[]> iceMelt = new LinkedList<>();
		int last_time = 0;
		int map[][] = new int [n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m; j++) {
				int tile = Integer.parseInt(st.nextToken());
				map[i][j] = tile;
			}
		}
		while(true){
			int visited[][] = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m ; j++){
					visited[i][j] = 0;
				}
			}
			int start[] = new int [2];
			start[0] = 0;
			start[1] = 0;
			q.add(start);
			//warm wind blow
			while (q.size() != 0){
				int cur[] = q.poll();
				int cur_r = cur[0];
				int cur_c = cur[1];
				if (visited[cur_r][cur_c] != 0)
					continue;
				visited[cur_r][cur_c] = 1;
				//wind blow
				for (int i = 0; i < 4; i++) {
					int next_r = cur_r + dr[i];
					int next_c = cur_c + dc[i];
					if (next_r < n && next_r > -1 && next_c < m && next_c > -1){
						int [] next_point = new int[2];
						next_point[0] = next_r;
						next_point[1] = next_c;
						//ice -> plus visited
						if (map[next_r][next_c] == 1){
							visited[next_r][next_c]++;
							if (visited[next_r][next_c] >= 2){
								iceMelt.add(next_point);
							}
						}
						else{
							q.add(next_point);
						}
					}
				}
			}
//			print(map);
			//noice
			if (iceMelt.size() == 0){
				break;
			}
			//icemelt
			last_time++;
			while(iceMelt.size() != 0){
				int iceCur[] = iceMelt.poll();
				int r = iceCur[0];
				int c = iceCur[1];
//				System.out.println(r+", "+c);
				map[r][c] = 0;
			}
		}
		System.out.println(last_time);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



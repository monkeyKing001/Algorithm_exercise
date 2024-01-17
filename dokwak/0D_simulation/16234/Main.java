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
		int l = 0, r = 0;
		l = m;
		r = Integer.parseInt(st.nextToken());
		int map[][] = new int [n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n ; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		ArrayList<ArrayList<int[]>> open = new ArrayList<>();
		int count = 0;
		while(open.size() != n * n){
			open.clear();
			int visited[][] = new int[n][n];
			Queue<int[]> q = new LinkedList<>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n ; j++){
					if (visited[i][j] == 0){
						ArrayList<int[]> openGroup = new ArrayList<>();
						int start[] = new int [2];
						start[0] = i;
						start[1] = j;
						q.add(start);
						open.add(openGroup);
						while (q.size() != 0){
							int cur[] = q.poll();
							int cur_r = cur[0];
							int cur_c = cur[1];
							if (visited[cur_r][cur_c] != 0)
								continue;
							visited[cur_r][cur_c] = open.size();
							openGroup.add(cur);
							for (int d_i = 0; d_i < 4; d_i++) {
								int next_r = cur_r + dr[d_i];
								int next_c = cur_c + dc[d_i];
								if (next_r < n && next_r > -1 && next_c < n && next_c >-1 && visited[next_r][next_c] == 0){
									int [] next_point = new int[2];
									next_point[0] = next_r;
									next_point[1] = next_c;
									if (l <= Math.abs(map[next_r][next_c] - map[cur_r][cur_c]) && 
											Math.abs(map[next_r][next_c] - map[cur_r][cur_c]) <= r){
										q.add(next_point);
									}
								}
							}
						}
						//finished bfs visit from start.
//						System.out.println("######    group report   #####");
//						for (int ii = 0; ii < n; ii++) {
//							for (int jj = 0; jj < n ; jj++){
//								System.out.print(visited[ii][jj] + " ");
//							}
//							System.out.println();
//						}
					}
				}
			}
			//no more move
			if (open.size() == n * n){
				break;
			}
			//population move!
			else{
				for (int o_i = 0; o_i < open.size(); o_i++) {
					ArrayList<int[]> openGroup = open.get(o_i);
					int sum = 0;
					if (openGroup.size() != 1){
						for (int g_i = 0; g_i < openGroup.size(); g_i++) {
							int cor[] = openGroup.get(g_i);
							int row = cor[0];
							int col = cor[1];
							sum += map[row][col];
						}
						for (int g_i = 0; g_i < openGroup.size(); g_i++) {
							int cor[] = openGroup.get(g_i);
							int row = cor[0];
							int col = cor[1];
							map[row][col] = sum / openGroup.size();
						}
					}
				}
				count++;
			}
		}
		System.out.println(count);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



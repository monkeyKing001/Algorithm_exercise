import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int map[][];
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
	static int totalWallNum = 0;
	static int sol = 0;
	static ArrayList<int[]> virus = new ArrayList<>();
	
	public static void rec(int wallNum){
		if (wallNum == 3){
			//map copy;
			//virus start;
			int copy[][] = new int[n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m ; j++){
					copy[i][j] = map[i][j];
				}
			}
			boolean visited[][] = new boolean[n][m];
			int safe = (n * m) - (totalWallNum + 3);
			Queue<int[]> q = new LinkedList<>();
			for (int i = 0; i < virus.size(); i++) {
				q.add(virus.get(i));
			}
			while (q.size() != 0){
				int cur[] = q.poll();
				int cur_r = cur[0];
				int cur_c = cur[1];
				if (visited[cur_r][cur_c])
					continue;
				visited[cur_r][cur_c] = true;
				safe--;
				copy[cur_r][cur_c] = 2;
				for (int i = 0; i < 4; i++) {
					int next_r = cur_r + dr[i];
					int next_c = cur_c + dc[i];
					if (next_r < n && next_r > -1 && next_c < m && next_c >-1 && !visited[next_r][next_c] && copy[next_r][next_c] == 0){
						int [] next_point = new int[2];
						next_point[0] = next_r;
						next_point[1] = next_c;
						q.add(next_point);
					}
				}
			}
			sol = Integer.max(sol, safe);
//			if (sol < safe){
//				System.out.println("new best case! safe : " + safe);
//				sol = Integer.max(sol, safe);
//				for (int i = 0; i < n; i++) {
//					for (int j = 0; j < m ; j++){
//						System.out.print(copy[i][j] + " ");
//					}
//					System.out.println();
//				}
//				System.out.println();
//			}
			return ;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				if (map[i][j] == 0){
					map[i][j] = 1;
					rec(wallNum + 1);
					map[i][j] = 0;
				}
			}
		}
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
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m ; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 2){
					int start[] = new int[2];
					start[0] = i;
					start[1] = j;
					virus.add(start);
				}
				if (map[i][j] == 1){
					totalWallNum++;
				}
			}
		}
		rec(0);
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



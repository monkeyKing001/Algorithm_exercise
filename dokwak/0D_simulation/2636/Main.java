import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 

	public static void printMap(int[][] map){
		System.out.println("#######        print       ##########");
		for (int i = 0; i < map.length; i++) {
			for (int j = 0; j < map[i].length ; j++){
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
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
		int air_r = 0;
		int air_c = 0;
		ArrayList<int[]> removeZone = new ArrayList<>();
		int map[][] = new int[n][m];
		int lastRemove = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m ; j++){
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int start [] = new int[2];
		start[0] = air_r;
		start[1] = air_c;
		int stage = 0;
		boolean finished = false;
		Queue<int[]> q = new LinkedList<>();
		while (!finished) {
			boolean visited[][] = new boolean[n][m];
//			printMap(map);
			removeZone.clear();
			q.add(start);
			while (q.size() != 0){
				int cur_air[] = q.poll();
				int cur_r = cur_air[0];
				int cur_c = cur_air[1];
				if (visited[cur_r][cur_c])
					continue;
				visited[cur_r][cur_c] = true;
				for (int d_i = 0; d_i < 4; d_i++) {
					int next_r = cur_r + dr[d_i];
					int next_c = cur_c + dc[d_i];
					int next [] = new int[2];
					if (next_r >= 0 && next_r < n  && next_c >= 0 && next_c < m && !visited[next_r][next_c]){
						if (map[next_r][next_c] == 0){
							next[0] = next_r;
							next[1] = next_c;
							q.add(next);
						}
						else if (map[next_r][next_c] == 1){
							next[0] = next_r;
							next[1] = next_c;
							removeZone.add(next);
							visited[next_r][next_c] = true;
						}
					}
				}
			}
			if (removeZone.size() == 0)
				break;
			for (int r_i = 0; r_i < removeZone.size(); r_i++) {
				int remove[] = removeZone.get(r_i);
				int remove_r = remove[0];
				int remove_c = remove[1];
				map[remove_r][remove_c] = 0;
			}
			stage++;
			lastRemove = removeZone.size();
		}
		System.out.println(stage);
		System.out.println(lastRemove);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

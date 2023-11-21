import java.util.*;
import java.io.*;

public class Main{
	//                 >   ^  <  v
	//                 cur_dir + -> L
	//                 cur_dir - -> R
	static int dr[] = {0, -1, 0, 1}; 
	static int dc[] = {1, 0, -1, 0}; 
	static char dchar[] = {'>', '^', '<', 'v'};
	static int init_dir_char;
	static int n, m;
	static int init_dir;
	static boolean finish = false;
	public static void printmap(int[][]map){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				System.out.print((char)map[i][j]);
			}
			System.out.println();
		}
		System.out.println();
	}
	public static void dfs(StringBuilder sb, int[][] cur_map, int cur_r, int cur_c, int cur_dir){
			int count = 0;
			//if finish, exit
			if (finish){
				return;
			}
			for (int k = 0; k < 4; k++) {
				int next_r = cur_r + dr[k];
				int next_c = cur_c + dc[k];
				if (next_r < n && next_r > -1 && next_c < m && next_c > -1 && cur_map[next_r][next_c] == '#'){
					count++;
				}
			}
			//made
			if (count == 0){
//				for (int i = 0; i < n; i++) {
//					for (int j = 0; j < m ; j++){
//						//wrong way! backtracking
//						if (cur_map[i][j] == '#'){
//
//						}
//					}
//				}
				//printmap(cur_map);
//				System.out.println("######   FINISH   #######");
				System.out.println(sb.toString());
				finish = true;
				return ;
			}
			int next_r = cur_r + dr[cur_dir];
			int next_c = cur_c + dc[cur_dir];
			int nnext_r = next_r + dr[cur_dir];
			int nnext_c = next_c + dc[cur_dir];
			//keep Move wit this dir
			if (next_r < n && next_r > -1 && next_c < m && next_c > -1 && cur_map[next_r][next_c] == '#'){
				if (nnext_r < n && nnext_r > -1 && nnext_c < m && nnext_c > -1 && cur_map[nnext_r][nnext_c] == '#'){
					sb.append("A");
					cur_map[next_r][next_c] = '.';
					cur_map[nnext_r][nnext_c] = '.';
					//printmap(cur_map);
					dfs(sb, cur_map, nnext_r, nnext_c, cur_dir);
				}
			}
			//turn left or right
			//left
			//right
			else{
				//L
				int next_dir_l = (cur_dir + 1) % 4;
				int l_r = cur_r + dr[next_dir_l];
				int l_c = cur_c + dc[next_dir_l];
				int ll_r = l_r + dr[next_dir_l];
				int ll_c = l_c + dc[next_dir_l];
				if (l_r < n && l_r > -1 && l_c < m && l_c > -1 && cur_map[l_r][l_c] == '#'){
					if (ll_r < n && ll_r > -1 && ll_c < m && ll_c > -1 && cur_map[ll_r][ll_c] == '#'){
						sb.append("LA");
						cur_map[l_r][l_c] = '.';
						cur_map[ll_r][ll_c] = '.';
						//printmap(cur_map);
						dfs(sb, cur_map, ll_r, ll_c, next_dir_l);
					}
				}
				//R
				else{
					int next_dir = cur_dir - 1;
//					System.out.println("cur_dir : " + dchar[cur_dir]);
					if (next_dir < 0)
						next_dir = 3;
//					System.out.println("next_dir : " + dchar[next_dir]);
					int r_r = cur_r + dr[next_dir];
					int r_c = cur_c + dc[next_dir];
					int rr_r = r_r + dr[next_dir];
					int rr_c = r_c + dc[next_dir];
					if (r_r < n && r_r > -1 && r_c < m && r_c > -1 && cur_map[r_r][r_c] == '#'){
						if (rr_r < n && rr_r > -1 && rr_c < m && rr_c > -1 && cur_map[rr_r][rr_c] == '#'){
							sb.append("RA");
							cur_map[r_r][r_c] = '.';
							cur_map[rr_r][rr_c] = '.';
							//printmap(cur_map);
							dfs(sb, cur_map, rr_r, rr_c, next_dir);
						}
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
		int map [][] = new int[n][m];
		for (int i = 0; i < n; i++) {
			String info = br.readLine();
			for (int j = 0; j < m ; j++){
				map[i][j] = info.charAt(j);
			}
		}
		ArrayList<int[]> start = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				if (map[i][j] =='#'){
					int count = 0;
					for (int k = 0; k < 4; k++) {
						int next_r = i + dr[k];
						int next_c = j + dc[k];
						if (next_r < n && next_r > -1 && next_c < m && next_c > -1 && map[next_r][next_c] == '#'){
							count++;
						}
					}
					if (count % 2 != 0){
						int next[] = new int[2];
						next[0] = i;
						next[1] = j;
						start.add(next);
					}
				}
			}
		}
		int start_r = start.get(0)[0];
		int start_c = start.get(0)[1];
		map[start_r][start_c] = '.';
		for (int i = 0; i < 4; i++) {
			int next_r = start_r + dr[i];
			int next_c = start_c + dc[i];
			if (next_r < n && next_r > -1 && next_c < m && next_c > -1 && map[next_r][next_c] == '#'){
				init_dir = i;
				init_dir_char = dchar[i];
			}
		}
		//printmap(map);
		System.out.println((start_r + 1) + " " + (start_c + 1));
		System.out.println((char)init_dir_char);
		dfs(sb, map, start_r, start_c, init_dir);
//		bw.write(sb.toString());
//		bw.flush();
		return ;
	}
}



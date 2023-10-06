import java.util.*;
import java.io.*;



public class Main{
	static int n, m;
	static int diag_r[] = {0, 1, 1};
	static int diag_c[] = {1, 0, 1};
	static int dir_r[] = {0, 1, 1};
	static int dir_c[] = {1, 0, 1};
	static int map[][];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		map = new int [n + 1][n + 1];
		for (int i = 1; i < n + 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 1; j < n + 1; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int sol = 0;
		if (map[n][n] == 1){
			System.out.println(sol);
			return;
		}
		//start[2] = 0 -> horiz, 
		//start[2] = 1 -> verti, 
		//start[2] = 2 -> diag
		int []start = new int[3];
		start[0] = 1;
		start[1] = 2;
		start[2] = 0;
		Queue<int[]> q = new LinkedList<>();
		q.add(start);
		while(q.size() != 0){
			int []cur = q.poll();
			int cur_r = cur[0];
			int cur_c = cur[1];
			int cur_dir = cur[2];
//			System.out.println("cur r, c, dir : "+cur_r+", "+cur_c+", "+cur_dir);
			if (cur_r == n && cur_c == n)
			{
//				System.out.println("######      arrived r, c, dir : "+cur_r+", "+cur_c+", "+cur_dir);
				sol++;
				continue;
			}
			//0 -> horiz
			//1 -> verti
			boolean diag_enable = true;
			for (int next_dir = 0; next_dir < 2; next_dir++) {
				int next_r = cur_r + dir_r[next_dir];
				int next_c = cur_c + dir_c[next_dir];
				if (next_r <= n && next_c <= n && map[next_r][next_c] == 0){
					if (cur_dir == 0 && next_dir == 1)
						continue;
					if (cur_dir == 1 && next_dir == 0)
						continue;
					int next[] = new int[3];
					next[0] = next_r;
					next[1] = next_c;
					next[2] = next_dir;
//					System.out.println("moving r, c, dir : "+next_r+", "+next_c+", "+next_dir);
					q.add(next);
				}
				else{
//					System.out.println("from r, c, dir : "+cur_r+", "+cur_c+", "+cur_dir);
//					System.out.println("$$$$$$$$     cannot move r, c, dir : "+next_r+", "+next_c+", "+next_dir);
					diag_enable = false;
				}
			}
			//2 -> diag
			int next_diag_r = cur_r + dir_r[2];
			int next_diag_c = cur_c + dir_c[2];
			if (diag_enable == true && next_diag_r <= n && next_diag_c <= n &&map[next_diag_r][next_diag_c] == 0){
				int next[] = new int[3];
				next[0] = next_diag_r;
				next[1] = next_diag_c;
				next[2] = 2;
//				System.out.println("moving r, c, dir : "+next_diag_r+", "+next_diag_c+", "+ 2);
				q.add(next);
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



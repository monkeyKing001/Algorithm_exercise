import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		System.out.println();
		String []j_map = new String[1010];
		String buf = "";
		int[][] f_visited = new int[1001][1001];
		int[][] j_visited = new int[1001][1001];
		int[] j_start = new int[2];
		int[] dr = {0, 1, 0, -1};
		int[] dc = {1, 0, -1, 0};
		int j_step = Integer.MAX_VALUE;
		Queue<int[]> q = new LinkedList<int[]>();
		Integer row, col, sol = 0;
		buf = br.readLine();
//		System.out.println("buf : " + buf);
		StringTokenizer st = new StringTokenizer(buf, " ");
		row = Integer.parseInt(st.nextToken());
//		System.out.println("row : " + row);
		col = Integer.parseInt(st.nextToken());
//		System.out.println("col : " + col);
		for (int i = 0; i < row; i++) {
			j_map[i] = br.readLine();
			for (int j = 0; j < col; j++) {
				if (j_map[i].charAt(j) == 'J')
				{
					j_start[0] = i;
					j_start[1] = j;
					j_visited[i][j] = 1;
				}
				else if (j_map[i].charAt(j) == 'F')
				{
					int []temp = new int[2];
					temp[0] = i;
					temp[1] = j;
					q.add(temp);
					f_visited[i][j] = 1;
				}
			}
		}
		//test out
//		for (int i = 0; i < row; i++) {
//			System.out.println(j_map[i]);
//		}
		while (q.size() != 0)
		{
			int c_r = q.peek()[0];
			int c_c = q.peek()[1];
			int c_step = f_visited[c_r][c_c];
			q.poll();
//			System.out.print("from " + c_r + ", " + c_c + " as " + f_visited[c_r][c_c]);
			for (int j = 0; j < 4; j++) {
				int n_r = c_r + dr[j];	
				int n_c = c_c + dc[j];	
				int n_step = c_step + 1;
				if (n_r > -1 && n_r < row && n_c > -1 && n_c < col && f_visited[n_r][n_c] == 0 && (j_map[n_r].charAt(n_c) == '.' || j_map[n_r].charAt(n_c) == 'J'))
				{
//					System.out.println("queing " + n_r + ", " + n_c + " as " + f_visited[n_r][n_c]);
					int []entry = {n_r, n_c};
					f_visited[n_r][n_c] = n_step;
					q.add(entry);
				}
			}
		}
		//print fire
//		for (int i = 0; i < row; i++) {
//			for (int j = 0; j < col; j++) {
//				System.out.print(f_visited[i][j]);
//			}
//			System.out.print("\n");
//			
//		}
		//bfs jh
		q.add(j_start);
		while (q.size() != 0)
		{
			int c_r = q.peek()[0];
			int c_c = q.peek()[1];
			int c_step = j_visited[c_r][c_c];
			q.poll();
			if ((c_r == 0 || c_r == row - 1 || c_c == 0 || c_c == col) && c_step < j_step)
				j_step = c_step;
			for (int i = 0; i < 4; i++) {
				int n_r = c_r + dr[i];
				int n_c = c_c + dc[i];
				int n_step = j_visited[c_r][c_c] + 1;
				if (n_r > -1 && n_r < row && n_c > -1 && n_c < col 
						&& j_visited[n_r][n_c] == 0
						&& j_map[n_r].charAt(n_c) == '.'
						&& (f_visited[n_r][n_c] == 0 || f_visited[n_r][n_c] > n_step))
				{
					int []entry = {n_r, n_c};
					q.add(entry);
					j_visited[n_r][n_c] = n_step;
				}
			}
		}
//		for (int i = 0; i < row; i++) {
//			for (int j = 0; j < col; j++) {
//				System.out.print(j_visited[i][j]);
//			}
//			System.out.print("\n");
//			
//		}
		if (j_step == Integer.MAX_VALUE)
			System.out.println("IMPOSSIBLE");
		else
			System.out.println(j_step);
		return ;
	}
}

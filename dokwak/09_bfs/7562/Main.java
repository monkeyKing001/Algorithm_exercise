import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		String buf = "";
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = 0;
		int sol = 0;
		int dr[] = {2, 2, -2, -2, -1, -1, 1, 1};
		int dc[] = {-1, 1, -1, 1, 2, -2, 2, -2};
		//n = Integer.parseInt(st.nextToken());
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++){
			int size = Integer.parseInt(br.readLine());
			int []start = new int[2];
			int []target = new int[2];
			int [][]board = new int[size][size];
			int r, c;
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			start[0] = Integer.parseInt(st.nextToken());
			start[1] = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine(), " ");
			target[0] = Integer.parseInt(st.nextToken());
			target[1] = Integer.parseInt(st.nextToken());
//			System.out.println("game start\nsize : " + size + "\nstart : " + start[0] + ", " + start[1]);
//			System.out.println("target : " + target[0] + ", " + target[1]);
			Queue<int[]> q = new LinkedList<int[]>();
			q.add(start);
			board[start[0]][start[1]] = 1;
			while (q.size() != 0)
			{
				int []point = q.poll();
				int c_r = point[0];
				int c_c = point[1];
				int c_step = board[c_r][c_c];
				if (c_r == target[0] && c_c == target[1])
				{
					System.out.println(board[c_r][c_c] - 1);
					break ;
				}
				for (int i = 0; i < 8; i++) {
					int n_r, n_c, n_step;
					n_r = c_r + dr[i];
					n_c = c_c + dc[i];
					n_step = c_step + 1;
					if (n_r > - 1 && n_r < size && n_c > -1 && n_c < size && board[n_r][n_c] == 0)
					{
						int []entry = {n_r, n_c};
						q.add(entry);
						board[n_r][n_c] = n_step;
					}
				}
			}
		}
//		System.out.println(n);
		return ;
	}
}


import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int path_num = 0;
	static int [][]map;
	static int [][]dp;
	static int []dr = {1, 0, -1 ,0};
	static int []dc = {0, 1, 0 ,-1};
	static boolean [][] visited;
	public static int rec(int cur_r, int cur_c){
		if (cur_r == n - 1 && cur_c == m - 1){
//			System.out.println("!!!!!!!!!!      Arrived     !!!!!!!");
			dp[cur_r][cur_c] = 1;
			return(dp[cur_r][cur_c]);
		}
		int cur_num = map[cur_r][cur_c];
		//first visit
		if (dp[cur_r][cur_c] == -1)
			dp[cur_r][cur_c] = 0;
		int count = 0;
		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];
			if (next_r > - 1 && next_r < n && next_c > -1 && next_c < m && map[next_r][next_c] < cur_num){
				if (dp[next_r][next_c] != -1)
				{
//					System.out.println("cur r, c : " + cur_r+ ", "+ cur_c);
//					System.out.println("already visted r, c : " + next_r + ", " + next_c + " : " +dp[next_r][next_c]);
					dp[cur_r][cur_c] += dp[next_r][next_c];
					count++;
				}
				//dfs go on
				else if (dp[next_r][next_c] != 0)
				{
//					System.out.println("cur r, c : " + cur_r+ ", "+ cur_c);
//					System.out.println("new way to r, c : " + next_r + ", " + next_c);
					dp[cur_r][cur_c] += rec(next_r, next_c);
					count++;
				}
			}
		}
		if (count == 0)
		{
			dp[cur_r][cur_c] = 0;
//			System.out.println("no way from here");
		}
		return (dp[cur_r][cur_c]);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int [n + 1][m + 1];
		dp = new int[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());	
				dp[i][j] = -1;
			}
		}
		int sol = rec(0, 0);
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				System.out.print(dp[i][j] + " ");
//			}
//			System.out.println();
//		}
		System.out.println(sol);
		return ;
	}
}

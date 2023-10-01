import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int block = Integer.parseInt(st.nextToken());
		int row = n;
		int col = m;
		int map[][] = new int [n][m];
		int dp[] = new int [257];
		int highest = 0;
		int lowest = 257;
		for (int i = 0; i < row; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < col; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				highest = Integer.max(highest, map[i][j]);
				lowest = Integer.min(lowest, map[i][j]);
			}
		}
		int min_cost = 256 * 500 * 500 * 2;
		int sol = -1;
		boolean keep_try = true;
		for(int i = lowest; i <= highest; i++){
			if (keep_try == false)
				break;
			int cur_blocks = block;
			int cur_cost = 0;
			int cur_map[][] = new int[n][m];
			int target_h = i;
			//copy map
			for (int row_i = 0; row_i < n; row_i++) {
				for (int col_i = 0; col_i < m; col_i++) {
					cur_map[row_i][col_i] = map[row_i][col_i];
				}
			}
			//1. removing all surplus blocks
			for (int row_i = 0; row_i < n; row_i++) {
				for (int col_i = 0; col_i < m; col_i++) {
					if (cur_map[row_i][col_i] > target_h){
						cur_blocks += (cur_map[row_i][col_i] - target_h);
						cur_cost += 2*(cur_map[row_i][col_i] - target_h);
						cur_map[row_i][col_i] = target_h;
					}
				}
			}
			//2. stacking all deficit blocks
			for (int row_i = 0; row_i < n; row_i++) {
				for (int col_i = 0; col_i < m; col_i++) {
					if (cur_map[row_i][col_i] < target_h){
						cur_cost += (target_h - cur_map[row_i][col_i]);
						cur_blocks -= (target_h - cur_map[row_i][col_i]);
						if (cur_blocks < 0)
						{
							cur_cost = 256 * 500 * 500 * 2;
							keep_try = false;//cannot try further height cases
							break;
						}
						cur_map[row_i][col_i] = target_h;
					}
				}
			}
			dp[i] = cur_cost;
			if (min_cost >= cur_cost){
				sol = i;
				min_cost = cur_cost;
			}
		}
		System.out.println(min_cost + " " + sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



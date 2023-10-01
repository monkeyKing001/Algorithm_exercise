import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int g_r;
	static int g_c;
	static int g_color;
	static boolean g_suc;
	static boolean g_print = false;
	static StringBuilder g_sb;
	static int map[][];
	public static void printWall(){
		System.out.print("YES\n");
		for (int i = 0; i < g_r; i++) {
			for (int j = 0; j < g_c; j++) {
				if (map[i][j] == 0)
					System.out.print("0 ");
				else
					System.out.print((map[i][j] - 1) + " ");
			}
			System.out.println();
		}
	}

	public static void fillWall(){
		int fill[][] = new int[g_r][g_c];
		for (int i = 0; i < g_r; i++) {
			int start_color = 2;
			if (i != 0)
				start_color = fill[i - 1][0]  + 1;
				if (start_color >= 2 + g_color)
					start_color = 2;
			fill[i][0] = start_color;
			for (int j = 1; j < g_c; j++) {
				fill[i][j] = fill[i][j - 1] + 1;
				if (fill[i][j] >= 2 + g_color)
					fill[i][j] = 2;
			}
		}
		for (int i = 0; i < g_r; i++) {
			for (int j = 0; j < g_c; j++) {
				if (map[i][j] == 1)
					map[i][j] = fill[i][j];
			}
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		g_sb = sb;

		//input
		n = Integer.parseInt(st.nextToken());
		int T = n;
		for (int t_i = 0; t_i < T; t_i++) {
			g_suc = true;
			g_print = false;
			st = new StringTokenizer(br.readLine()," ");
			int row = Integer.parseInt(st.nextToken());
			int col = Integer.parseInt(st.nextToken());
			g_r = row;
			g_c = col;
			int color_num = Integer.parseInt(st.nextToken());
			g_color = color_num;
			//map init;
			map = new int [row][col];
			int dp[][][] = new int [row][col][2];
			for (int row_i = 0; row_i < row; row_i++) {
				st = new StringTokenizer(br.readLine()," ");
				for (int col_i = 0; col_i < col; col_i++) {
					map[row_i][col_i] = Integer.parseInt(st.nextToken());
				}
			}
			for (int row_i = 0; row_i < row && g_suc == true; row_i++) {
				for (int col_i = 0; col_i < col; col_i++) {
					dp[row_i][col_i][0] = 0;//row dp
					dp[row_i][col_i][1] = 0;//col dp
					if (map[row_i][col_i] == 0)
						continue;
					int up_r = row_i - 1;
//					System.out.println("can paint in r, c : " + row_i + ", " + col_i);
					//up check
					if (up_r > -1){
						dp[row_i][col_i][0] = dp[up_r][col_i][0] + 1;
					}
					else
					{
						dp[row_i][col_i][0] = 1;
					}
					int left_c = col_i - 1;
					if (left_c > -1){
						dp[row_i][col_i][1] = dp[row_i][left_c][1] + 1;
					}
					else
					{
						dp[row_i][col_i][1] = 1;
					}
					if (Integer.max(dp[row_i][col_i][0], dp[row_i][col_i][1]) > color_num)
					{
						g_suc = false;
						break;
					}
				}
			}
//			for (int i = 0; i < row; i++) {
//				for (int col_i = 0; col_i < col; col_i++) {
//					System.out.print(dp[i][col_i][0] + ", " + dp[i][col_i][1] + "    ");
//				}
//				System.out.println();
//			}
			if (g_suc == false)
				System.out.println("NO");
			else{
				fillWall();
				printWall();
			}
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

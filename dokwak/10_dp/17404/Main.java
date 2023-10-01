import java.util.*;
import java.io.*;

public class Main{
	public static int RED = 0, GREEN = 1, BLUE = 2;
	public static int max = 10000000;

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		int n = Integer.parseInt(br.readLine());
		int cost[][] = new int [n + 1][3];
		int dp[][][] = new int [3][n + 1][3];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int r, g, b;
			r = Integer.parseInt(st.nextToken());
			g = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			cost[i][RED] = r;
			cost[i][GREEN] = g;
			cost[i][BLUE] = b;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][0][j] = (i == j) ? cost[0][i] : max;
			}
		}
		for (int first_house_color = 0; first_house_color < 3; first_house_color++) {
//			System.out.println("first_house_color : " + first_house_color);
			for (int j = 1; j < n; j++) {
				for (int cur_color = 0; cur_color < 3; cur_color++) {
					//cur_house colort RED
					int other_color_one = -1;
					int other_color_two = -1;
					if (cur_color == RED)
					{
						other_color_one = GREEN;
						other_color_two = BLUE;
					}
					else if (cur_color == GREEN){
						other_color_one = RED;
						other_color_two = BLUE;
					}
					else if (cur_color == BLUE){
						other_color_one = GREEN;
						other_color_two = RED;
					}
					dp[first_house_color][j][cur_color] = 
						Integer.min(
								dp[first_house_color][j - 1][other_color_one], 
								dp[first_house_color][j - 1][other_color_two]);
//					System.out.println("layer, color, cost : " + j + ", " + cur_color + ", " + dp[first_house_color][j][cur_color]);
					if (dp[first_house_color][j][cur_color] != max)
						dp[first_house_color][j][cur_color] += cost[j][cur_color]; 
				}
			}
		}
		//input
		//n = Long.parseInt(st.nextToken());
		int sol = Integer.MAX_VALUE;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j)
					continue;
				sol = Integer.min(dp[i][n - 1][j], sol);
			}
		}
		System.out.println(sol);
		return ;
	}
}


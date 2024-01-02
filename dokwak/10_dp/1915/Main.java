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
		int map [][] = new int[n + 1][m + 1];
		int dp [][] = new int[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			String str = br.readLine();
			for (int j = 0; j < m ; j++){
				map[i + 1][j + 1] = str.charAt(j) - '0';
			}
		}
		int len = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++){
				if(map[i + 1][j + 1] == 0){
					dp[i + 1][j + 1] = 0;
				}
				else if (map[i + 1][j + 1] == 1){
//					if (map[i][j + 1] == map[i + 1][j] && map[i + 1][j] == 1){
						dp[i + 1][j + 1] = Integer.min(dp[i + 1][j] , dp[i][j + 1]);
						dp[i + 1][j + 1] = Integer.min(dp[i + 1][j + 1] , dp[i][j]);
						dp[i + 1][j + 1]++;
//					}
//					else
//						dp[i + 1][j + 1] = 1;
				}
				len = Integer.max(len, dp[i + 1][j + 1]);
			}
		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m ; j++){
//				System.out.print(dp[i + 1][j + 1]);
//			}
//			System.out.println();
//		}
		System.out.println(len * len);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



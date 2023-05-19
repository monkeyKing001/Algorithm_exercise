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
		int [][]dp = new int[101][100001];
		ArrayList<int[]> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int [] entry = new int[2];
			entry[0] = Integer.parseInt(st.nextToken()); //w
			entry[1] = Integer.parseInt(st.nextToken()); //v
			arr.add(entry);
//			System.out.println("w, v : " + entry[0] +", "+ entry[1]);
		}
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 100001; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			int w = arr.get(i - 1)[0];
			int v = arr.get(i - 1)[1];
			for (int j = 0; j <= m; j++) {
				if (j < w)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					if (dp[i - 1][j - w] + v > dp[i - 1][j]) //best value in under v[j-w] + cur_v vs best_value under v[j] in past
						dp[i][j] = dp[i - 1][j - w] + v;
					else
						dp[i][j] = dp[i - 1][j];
				}
			}
		}
//		for (int i = 0; i <= n; i++) {
//			System.out.print("item " + i + " : ");
//			for (int j = 0; j <= m; j++) {
//				System.out.print(dp[i][j] + "\t");
//			}	
//			System.out.println("");
//		}
		System.out.println(dp[n][m]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



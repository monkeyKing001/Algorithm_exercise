import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int cal = 0;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			n = Integer.parseInt(st.nextToken());
			ArrayList<Integer> arr = new ArrayList<>();
			st = new StringTokenizer(br.readLine()," ");
			int dp[][] = new int[n + 1][n + 1];
			int novel [] = new int [n + 1];
			for (int i = 0; i < n; i++) {
				int num = Integer.parseInt(st.nextToken());
				arr.add(num);
				novel[i + 1] = novel[i] + num;
			}
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1 ; j++){
					dp[i][j] = 0;
//					if (i == j)
//						dp[i][j] = novel[i] - novel[i - 1];
				}
			}
			for (int size = 1; size < n; size++) {
//				System.out.println("size : " + size);
				for (int start = 1; start < n + 1 - size ; start++){
					int end = start + size;
					dp[start][end] = Integer.MAX_VALUE;
//					System.out.println("finding min from ~ to : " + start + " ~ "+ end);
					for (int div = 0; div < size; div++) {
						int mid = start + div;
//						System.out.print("trying : " + start + " ~ "+ mid + " vs ");
//						System.out.println((mid + 1) + " ~ "+ end);
						dp[start][end] = Integer.min(
								dp[start][end],
								dp[start][mid] + dp[mid + 1][end] + novel[end] - novel[start - 1]
								);
					}
				}
//				for (int i = 1; i < n + 1; i++) {
//					for (int j = 1; j < n + 1 ; j++){
//						System.out.print(dp[i][j] + " ");
//					}
//					System.out.println();
//				}
			}
			System.out.println(dp[1][n]);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



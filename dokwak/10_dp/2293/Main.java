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
		int max = 10000;
		ArrayList<Integer> arr = new ArrayList<>();
		int dp[] = new int [100001]; 
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int num = Integer.parseInt(st.nextToken());
			arr.add(num);
		}
		arr.sort(Comparator.naturalOrder());
		for (int i = 0; i < arr.size(); i++) {
			int coin = arr.get(i);
			for (int j = coin; j <= max; j++) {
				dp[j] += dp[j - coin];
			}
//			for (int j = 1; j <= m; j++) {
//				System.out.print(dp[j] + " ");
//			}
//			System.out.println();
		}
//		System.out.println();
		sb.append(dp[m]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



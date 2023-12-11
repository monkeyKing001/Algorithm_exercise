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
		ArrayList<Integer> arr = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int coin = Integer.parseInt(st.nextToken());
			arr.add(coin);
		}
//		arr.sort(Comparator.naturalOrder());
		int max = 1000001;
		int dp[] = new int [max];
		for (int i = 0; i < max; i++) {
			dp[i] = max;
		}
		dp[0] = 0;
		for (int i = 0; i < arr.size(); i++) {
			int coin = arr.get(i);
			for (int j = coin; j < max; j++) {
				dp[j] = Integer.min(dp[j - coin] + 1, dp[j]);
			}
		}
		if (dp[m] == max)
			sb.append(-1);
		else
			sb.append(dp[m]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



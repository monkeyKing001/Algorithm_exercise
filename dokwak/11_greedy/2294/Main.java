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
		int [] dp = new int[10001];
		for (int i = 0; i < 10001; i++) {
			dp[i] = 10001;
		}
		dp[0] = 0;
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ArrayList<Integer> coins = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int coinValue = Integer.parseInt(st.nextToken());
			coins.add(coinValue);
		}
		coins.sort(null);
		for (int i = 0; i < coins.size(); i++) {
			int coinValue = coins.get(i);
			if (coinValue > 10000)
				continue;
			dp[coinValue] = 1;
			for (int updateValue = coinValue; updateValue < 10001; updateValue++) {
				dp[updateValue] = Integer.min(dp[updateValue], dp[updateValue - coinValue] + 1);
			}
		}
		int sol = -1;
		if (dp[m] != 10001)
			sol = dp[m];
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



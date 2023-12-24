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
		int k = m;
		int dp[] = new int [n + 1];
		long sol = 0;
		Map<Integer, Integer> map = new HashMap<>();
		map.put(0, 1);
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			dp[i + 1] = dp[i] + num;
			int target = dp[i + 1] - k;
//			System.out.println("target : " + target);
//			System.out.println("sol : " + sol);
			sol+= map.getOrDefault(target, 0);
//			System.out.println("found : " + map.getOrDefault(target, 0));
//			System.out.println("sol : " + sol);
			map.put(dp[i + 1], map.getOrDefault(dp[i + 1], 0) + 1);
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

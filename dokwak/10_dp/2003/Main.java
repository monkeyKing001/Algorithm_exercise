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
		int dp[] = new int[10001];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			dp[i + 1] = Integer.parseInt(st.nextToken()) + dp[i];
		}
		int sol = 0;
		for (int i = 0; i <= n - 1; i++) {
			for (int j = i + 1; j <= n ; j++){
				if (dp[j] - dp[i] == m)
					sol++;
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



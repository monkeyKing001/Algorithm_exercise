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
		String str = br.readLine();
		int []dp = new int[21];
		long sol = 1;
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i < 21; i++) {
			dp[i] = dp[i - 2] + dp[i - 1];
		}
		str = str.replace("long", "*");
		int l = 0;
		while (l < str.length()){
			if (str.charAt(l) == '*'){
				int r = l + 1;
				while (r < str.length() && str.charAt(r) == '*'){
					r++;
				}
				int len = r - l;
				sol *= dp[len];
				l = r;
			}
			l++;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



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
		double constMinTan = -1000000000;
		int build [] = new int [n];
		int dp [] = new int [n];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			build[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < n - 1; i++) {
			double rightminTan = constMinTan;
			for (int r = i + 1; r < n; r++) {
				double tan = (double)(build[r] - build[i]) / (double)(r - i);
				if (tan > rightminTan){
					rightminTan = tan;
					dp[i]++;
					dp[r]++;
				}
			}
		}
		int sol = 0;
		for (int i = 0; i < n; i++) {
			sol = Integer.max(dp[i], sol);
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

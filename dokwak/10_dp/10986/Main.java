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
		int [] dp = new int[n + 1];
		int [] mDp = new int [m + 1];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			dp[i + 1] = ((Integer.parseInt(st.nextToken()) % m) + (dp[i] % m)) % m;
			mDp[dp[i + 1]]++;
		}
		long sol = 0;
		for (int i = 0; i < m; i++) {
			if (i == 0 && mDp[i] != 0){
				sol += mDp[i];
				sol += ((long)mDp[i] * (long)(mDp[i] - 1)) / (long)2;
			}
			else if (mDp[i] > 1){
				sol += ((long)mDp[i] * (long)(mDp[i] - 1)) / 2;
			}
		}
//		System.out.println("sol 1 : " + sol);
//		sol = 0;
//		System.out.println("#dp");
//		for (int i = 1; i < n + 1; i++) {
//			System.out.print(dp[i] + " ");
//		}
//		System.out.println();
//		for (int i = 0; i < n; i++) {
//			for (int j = i + 1; j <= n ; j++){
//				int temp = ((dp[i] % m) - (dp[j] % m)) % m;
//				if (temp == 0){
//					sol++;
//					System.out.println("from ~ to is mod 0 : " + (i + 1) + " ~ " + j);
//				}
//			}
//		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



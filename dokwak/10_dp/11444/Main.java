import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static long n, m;
	static long mod = 1000000007;
	static long [][] ans = new long [2][2];
	public static long [][] multiple_mat(long [][]a, long [][]b)
	{
		long [][] ret = new long [2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ret[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					ret[i][j] += a[i][k] * b[k][j]; 
				}
				ret[i][j] %= mod;
			}
		}
		return (ret);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		m = Long.parseLong(st.nextToken());
		ans [0][0] = 1;
		ans [0][1] = 0;
		ans [1][0] = 0;
		ans [1][1] = 1;
		long [][] a = new long [2][2];
		a[0][0] = 1;
		a[0][1] = 1;
		a[1][0] = 1;
		a[1][1] = 0;
		while (m > 0)
		{
			if (m % 2 == 1)
				ans = multiple_mat(ans, a);
			a = multiple_mat(a, a);
			m /= 2;
		}
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < 2; j++) {
//				System.out.print(ans[i][j] + "\t");
//			}
//			System.out.println("");
//		}
		System.out.println(ans[0][1]);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

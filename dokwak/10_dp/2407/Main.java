import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
	static int n, m;
	static BigInteger [][]mul = new BigInteger [102][102];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		mul[0][0] = new BigInteger("1");
		for (int i = 1; i < 101; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i)
				{
					mul[i][j] = new BigInteger("1");
					continue;
				}
				mul[i][j] = new BigInteger("0");
				int a = i - 1;
				int b = j - 1;
				while (a >= 0 && b >= 0 && a >= b)
				{
					mul[i][j] = mul[i][j].add(mul[a][b]);
					a--;
				}
			}
		}
		System.out.println(mul[n][m]);
		return ;
	}
}

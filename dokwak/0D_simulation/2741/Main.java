import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		int n = Integer.parseInt(st.nextToken());
		long a = (long)n;
		String str = br.readLine();
		long dp[][] = new long[50][27];
		BigInteger result = new BigInteger("0");
		for(int i = 0; i < str.length(); i++) {
			result = result.add(BigInteger.valueOf(str.charAt(i) - 'a' + 1).multiply(BigInteger.valueOf(31).pow(i)));
		}
		sb.append(result.remainder(BigInteger.valueOf(1234567891)));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



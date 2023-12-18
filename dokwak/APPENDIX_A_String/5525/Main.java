import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static long seed = 2;
	static long mod = Long.MAX_VALUE;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		long hash = 0;
		int hashLen = 2 * n + 1;
		String hashString = "";
		for (int i = 0; i < hashLen; i++) {
			if (i % 2 == 0)
			{
				hash += ('I' - 'A') * (long)Math.pow(seed, i + 1) ;
				hashString += "I";
			}
			else
			{
				hash += ('O' - 'A') * (long)Math.pow(seed, i + 1) ;
				hashString += "O";
			}
			hash %= mod;
		}
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
		long target = 0;
		long prev = 0;
		int sol = 0;
		String str = br.readLine();
		for (int i = 0; i <= str.length() - hashString.length(); i++) {
			String subStr = str.substring(i, i + hashLen);
			if (subStr.compareTo(hashString) == 0)
				sol++;
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
//		for (int i = 0; i < hashLen && i < str.length(); i++) {
//			target += (long)(str.charAt(i) - 'A') * (long)Math.pow(seed, i + 1);
//			target %= mod;
//		}
//		if (target == hash)
//			sol++;
//		for (int i = hashLen; i < str.length(); i++) {
//			prev = (str.charAt(i - hashLen) - 'A') * 2;
//			target -= prev;
//			target /= seed;
//			target += (long)(((long)(str.charAt(i) - 'A')) * (long)Math.pow(seed, hashLen));
//			target %= mod;
//			if (target == hash){
//				sol++;
//			}
//		}
//		sb.append(sol);
//		bw.write(sb.toString());
//		bw.flush();
//		return ;
	}
}



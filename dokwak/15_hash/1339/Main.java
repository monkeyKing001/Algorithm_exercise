import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static long pow_10(int i){
		long result = 1;
		int count = 0;
		while(count < i){
			result *= 10;
			count++;
		}
		return(result);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		Map<Character, Long> m =new HashMap<>();
		long dp[] = new long[26];
		for (int i = 0; i < n; i++) {
			String input = br.readLine();
			for (int j = 0; j < input.length(); j++) {
				int chr_int = input.charAt(j) - 'A';
				dp[chr_int] += pow_10(input.length() - j - 1);
			}
		}
		Arrays.sort(dp);
		int digit = 9;
		int i = 25;
		long sol = 0;
		while (dp[i] != 0){
			sol += digit * dp[i];
			i--;
			digit--;
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



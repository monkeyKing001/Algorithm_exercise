import java.util.*;
import java.io.*;

public class Main{
	static long n, p, k;
	static long div = 1000000007L;

	public static int findbiggestSmallLen(int len){
		int sol = 1;
		int find_len = 1;
		while(Math.pow(2, find_len + 1) < len)
		{
			find_len++;
		}
		return (find_len);
	}

	public static long rec(long n){
		if (n == 1)
			return p;
		long cur = rec(n/2);
		if (n % 2 == 1){
			return (((cur % div) * (cur % div) * p % div)% div); 
		}
		else{
			return ((cur % div) * (cur % div) % div); 
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		k = Long.parseLong(st.nextToken());
		p = Long.parseLong(st.nextToken());
		n = Long.parseLong(st.nextToken());
//		long time = (n * 10);
//		long cur_time = 1;
//		long [] dp = new long[100000];
//		int sq = 1;
//		dp[0] = 1;
//		dp[1] = p;
//		while (cur_time <= time){
////			System.out.println("cur_time : " + cur_time);
//			dp[sq] = p;
////			System.out.println("cur_p : " + dp[sq]);
//			sq++;
//			cur_time *= 2; 
//			p *= p;
//			p %= div;
//		}
//		cur_time /= 2;
		sb.append(rec(n * 10));
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



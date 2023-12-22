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
		String str = st.nextToken();
		int sol = 0;
		int one = 0;
		int zero = 0;
//		System.out.println("str : " + str);
		st = new StringTokenizer(str,"0");
		while (st.hasMoreTokens()){
			one++;
			st.nextToken();
		}
		st = new StringTokenizer(str,"1");
		while (st.hasMoreTokens()){
			zero++;
			st.nextToken();
		}
		sol = Integer.min(zero, one);
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



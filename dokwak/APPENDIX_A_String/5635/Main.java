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
		int early = Integer.MAX_VALUE;
		String oldest = "";
		int late = Integer.MIN_VALUE;
		String youngest  = "";
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			String name = st.nextToken();
			int day = Integer.parseInt(st.nextToken()) + 100;
			int month = (Integer.parseInt(st.nextToken()) + 100)  * 1000;
			int year = Integer.parseInt(st.nextToken());
			int hash = year * 1000000;
			hash += month;
			hash += day;
//			sb.append(name +"\n");
//			sb.append(hash +"\n");
			if (hash < early){
				early = hash;
				oldest = name;
			}
			if (hash > late){
				late = hash;
				youngest = name;
			}
		}
		sb.append(youngest + "\n" + oldest);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



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
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			m = Integer.parseInt(st.nextToken());
			min = Integer.min(min, m);
			max = Integer.max(max, m);
		}
		sb.append(min + " " + max);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



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
		long sum = 0;
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			sum += Integer.parseInt(st.nextToken());
		}
		System.out.println(sum);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

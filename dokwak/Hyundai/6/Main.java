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
		int [] arr = new int[n];
		int [] meter = new int[n];
		int len = n;
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			meter[i] = Integer.parseInt(st.nextToken());
			if (meter[i] > arr[i])
			{
				sb.append("-1");
				bw.write(sb.toString());
				bw.flush();
				return ;
			}
		}
		st = new StringTokenizer(br.readLine()," ");
		m = Integer.parseInt(st.nextToken());
//		System.out.println("press : " + m);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



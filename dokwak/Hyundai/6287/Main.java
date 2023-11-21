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
		long [] a = new long [n + 1];
		long [] b = new long [n + 1];
		long [] atob = new long [n + 1];
		long [] btoa = new long [n + 1];
		long [] dpa = new long[n + 1];
		long [] dpb = new long [n + 1];
		for (int i = 1; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int a_t = Integer.parseInt(st.nextToken());
			int b_t = Integer.parseInt(st.nextToken());
			int ab = Integer.parseInt(st.nextToken());
			int ba = Integer.parseInt(st.nextToken());
			a[i] = a_t;
			b[i] = b_t;
			atob[i] = ab;
			btoa[i] = ba;
		}
		st = new StringTokenizer(br.readLine()," ");
		a[n] = Integer.parseInt(st.nextToken());
		b[n] = Integer.parseInt(st.nextToken());
		dpa[1] = a[1];
		dpb[1] = b[1];
		for (int i = 2; i < n + 1; i++) {
			dpa[i] = Long.min(dpa[i - 1], dpb[i - 1] + btoa[i - 1]) + a[i];
			dpb[i] = Long.min(dpb[i - 1], dpa[i - 1] + atob[i - 1]) + b[i];
//			System.out.println("dpa " + i + " " + dpa[i]);
//			System.out.println("dpb " + i + " " + dpb[i]);
		}
		long sol = Long.min(dpa[n], dpb[n]);
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



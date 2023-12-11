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
		m = Integer.parseInt(st.nextToken());
		int willToPay[] = new int[m];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			willToPay[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(willToPay);
		int sol = 0;
		int solPrice = -1;
		for (int i = 0; i < m; i++) {
			int price = willToPay[i];
			int quantity = 0;
			if (m - i > n){
				quantity = n;
			}
			else
				quantity = m - i;
			int rev = quantity * price;
			if (rev > sol){
				sol = Integer.max(sol, rev);
				solPrice = price;
			}
		}
		sb.append(solPrice+ " " + sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



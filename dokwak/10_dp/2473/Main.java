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
		int arr[] = new int [n];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n / 2; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = n; i < n; i++) {
			
		}
		int left[] = new int[ n / 2 ];
		int right[] = new int [n / 2 ];
		m = Integer.parseInt(st.nextToken());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

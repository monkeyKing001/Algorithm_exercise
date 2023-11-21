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
		st = new StringTokenizer(br.readLine()," ");
		int [] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		long sol = 0;
		for (int i = 0; i < arr.length - 2; i++) {
			int count = 0;
			for (int j = n - 1; j > i; j--) {
				if (arr[j] > arr[i]) {
					sol+= count;
				}
				else if (arr[j] <= arr[i]) {
					count++;
				}
			}
		}
		sb.append(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}

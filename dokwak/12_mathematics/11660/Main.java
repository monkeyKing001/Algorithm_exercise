import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int[] arr = new int[1100 * 1100];
	static int[] sum_arr = new int[1100 * 1100];
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			for (int j = 0; j < n; j++) {
				int temp = Integer.parseInt(st.nextToken());
				if (i == 0 && j == 0)
					sum_arr[0] = temp;
				else
					sum_arr[(i * n) + j] = sum_arr[(i * n) + j - 1] + temp; 
			}
		}
		int x1, y1;
		int x2, y2;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine()," ");
			x1 = Integer.parseInt(st.nextToken());
			y1 = Integer.parseInt(st.nextToken());
			x2 = Integer.parseInt(st.nextToken());
			y2 = Integer.parseInt(st.nextToken());
			long sum = 0;
			for (int j = x1; j <= x2; j++) {
				//s2 - s1
				int start = (j - 1) * n + (y1 - 1);
				int end = start + (y2 - y1);
				long s1 = sum_arr[end];
				if (start != 0)
					s1 -= sum_arr[start - 1];
				sum+= s1;
			}
			sb.append(String.valueOf(sum));
			sb.append("\n");
		}
		System.out.print(sb.toString());
		return ;
	}
}

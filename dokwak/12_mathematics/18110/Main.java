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
		int arr [] = new int[n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine()," ");
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		int Percent15 = (int)Math.round((float)n * 15 / 100);
		int start = Percent15;
		int end = n - Percent15 - 1;
		int sum = 0;
		while (start <= end){
			sum += arr[start];
			start++;
		}
		int avg = Math.round((float)sum / (end - Percent15 + 1));
		sb.append(avg);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



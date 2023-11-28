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
		int cur_n = 1;
		int l = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int max_a = (int)Math.pow(2, r - 1);
		int min_a = (int)Math.pow(2, l - 1);
		int a = 1;
		int biggest[] = new int[n];
		int smallest[] = new int[n];
		int biggest_sum =  0;
		int smallest_sum =  0;
		for (int i = 0; i < n; i++) {
			biggest[i] = a;
			if (a != max_a)
				a *= 2;
			biggest_sum+=biggest[i];
		}
		a = 1;
		for (int i = 0; i < n; i++) {
			smallest[i] = a;
			if (a <= min_a)
				a *= 2;
			else
				smallest[i] = 1;
			smallest_sum+=smallest[i];
		}
		System.out.println(smallest_sum + " " + biggest_sum);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}



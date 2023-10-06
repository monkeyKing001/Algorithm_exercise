import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int d, piz_n;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		d = n;
		piz_n = m;
		int ovens[] = new int[d];
		int pizzas [] = new int [piz_n];
		int dp[] = new int[piz_n];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < d; i++) {
			ovens[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < piz_n; i++) {
			pizzas[i] = Integer.parseInt(st.nextToken());
			dp[i] = -1;
		}
		int last_depth_i = d;
		for (int i = 0; i < piz_n; i++) {
			int piz_diam = pizzas[i];
			int cur_depth_i = 0;
			int cur_depth_diam = ovens[cur_depth_i];
			while (cur_depth_i < last_depth_i && cur_depth_i < d){
				cur_depth_diam = ovens[cur_depth_i];
				if (cur_depth_diam < piz_diam)
					break;
				cur_depth_i++;
			}
			//pizza overflow
			if (cur_depth_i == 0 && last_depth_i == 0)
			{
				System.out.println(0);
				return;
			}
			dp[i] = cur_depth_i;
			last_depth_i = cur_depth_i;
		}
//		for (int i = 0; i < piz_n; i++) {
//			System.out.println(dp[i] + 1);
//		}
		System.out.println(dp[piz_n - 1] + 1);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
